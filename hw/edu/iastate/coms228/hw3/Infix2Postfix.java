package edu.iastate.cs228.hw3;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

/**
 *
 */

enum State {
    Operator, Operand
}

public class Infix2Postfix {
    private final Stack<Character> stack;
    private final Stack<State> states;
    private final Queue<String> queue;
    private final String input;

    public Infix2Postfix(String input) {
        this.stack = new Stack<>();
        this.states = new Stack<>();
        this.queue = new LinkedList<>();
        this.states.push(State.Operand);
        this.input = input;
    }

    public static boolean isOperator(char ch) {
        switch (ch) {
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            case '%':
                return true;
            default:
                return false;
        }
    }

    public static boolean isOperand(char ch) {
        return Character.isDigit(ch);
    }

    private static int priority(char ch) {
        switch (ch) {
            case '^':
                return 5;
            case '/':
            case '*':
                return 4;
            case '+':
            case '-':
                return 3;
            case '%':
                return 1;
            default:
                return 0;
        }

    }

    public void translate() {
        int index = 0;
        while (index < input.length()) {
            char ch = input.charAt(index);

            // check operand
            String prefix = "";
            if (ch == '-') {
                // check negative number
                if (isOperand(input.charAt(index + 1))) {
                    prefix = "-";
                    ch = input.charAt(++index);
                }
            }
            if (isOperand(ch)) {
                int p = index;
                while (p < input.length() && isOperand(input.charAt(p))) {
                    p++;
                }
                String number = prefix + input.substring(index, p);
                queue.add(number);
                if (states.peek() != State.Operand) {
                    throw new Error(String.format("too many operands (%s)", number));
                }
                index = p;
                states.pop();
                states.push(State.Operator);
                continue;
            }
            // check opening parenthesis
            else if (ch == '(') {
                states.pop();
                states.push(State.Operator); // current level
                states.push(State.Operand); // next level
                stack.push(ch);
            }
            // check closing parenthesis
            else if (ch == ')') {
                int preSize = stack.size();

                try {
                    while (stack.peek() != '(') {
                        queue.add(stack.pop() + "");
                    }
                } catch (EmptyStackException error) {
                    throw new Error("no opening parenthesis detected");
                }

                int afterSize = stack.size();
                if (preSize == afterSize) {
                    throw new Error("no subexpression detected ()");
                }
                stack.pop();
                states.pop();
            }
            // check operators
            else if (isOperator(ch)) {
                if (states.peek() != State.Operator) {
                    throw new Error(String.format("too many operators (%s)", ch));
                }
                if (stack.isEmpty()) {
                    stack.push(ch);
                } else if (stack.peek() == '(') {
                    stack.push(ch);
                } else if (priority(ch) > priority(stack.peek())) {
                    stack.push(ch);
                } else if (priority(ch) <= priority(stack.peek())) {
                    queue.add(stack.pop() + "");
                    stack.push(ch);
                }
                states.pop();
                states.push(State.Operand);
            }

            // next char
            index++;
        }

        // clean stack
        while (!stack.empty()) {
            char head = stack.pop();
            if (head == '(') {
                throw new Error("no closing parenthesis detected");
            }
            queue.add(head + "");
        }
    }

    public String generateOutput() {
        StringBuilder stringBuilder = new StringBuilder();
        while (!queue.isEmpty()) {
            String head = queue.remove();
            String suffix = " ";
            if (queue.isEmpty()) {
                suffix = "";
            }
            stringBuilder.append(head).append(suffix);
        }
        return stringBuilder.toString();
    }

    public static void main(String[] args) throws FileNotFoundException {
        File file = new File("input.txt");
        Scanner scanner = new Scanner(file);
        File outputFile = new File("output.txt");
        PrintWriter printWriter = new PrintWriter(outputFile);

        while (scanner.hasNextLine()) {
            String input = scanner.nextLine();
            Infix2Postfix infix2Postfix = new Infix2Postfix(input);
            try {
                infix2Postfix.translate();
            } catch (Error error) {
                printWriter.println("Error: " + error.getMessage());
                continue;
            }
            String output = infix2Postfix.generateOutput();
            printWriter.println(output);
        }
        printWriter.close();
    }
}
