package edu.iastate.cs228.hw2;

/**
 *
 */

import java.util.ArrayList;
import java.util.ListIterator;

public class PrimeFactorization implements Iterable<PrimeFactor> {
    private static final long OVERFLOW = -1;
    private long value;    // the factored integer
    // it is set to OVERFLOW when the number is greater than 2^63-1, the
    // largest number representable by the type long.

    /**
     * Reference to dummy node at the head.
     */
    private Node head;

    /**
     * Reference to dummy node at the tail.
     */
    private Node tail;

    private int size;        // number of distinct prime factors


    // ------------
    // Constructors
    // ------------

    /**
     * Default constructor constructs an empty list to represent the number 1.
     * <p>
     * Combined with the add() method, it can be used to create a prime factorization.
     */
    public PrimeFactorization() {
        this.init();
    }


    /**
     * Obtains the prime factorization of n and creates a doubly linked list to store the result.
     * Follows the direct search factorization algorithm in Section 1.2 of the project description.
     *
     * @param n
     * @throws IllegalArgumentException if n < 1
     */
    public PrimeFactorization(long n) throws IllegalArgumentException {
        if (n < 1) {
            throw new IllegalArgumentException();
        }
        this.init();
        this.value = n;

        for (int i = 2; i <= n; i++) {
            if (n < i) {
                break;
            }
            if (n % i == 0) {
                int m = 0;
                while ((n % i) == 0) {
                    n /= i;
                    m++;
                }
                this.link(this.tail, new Node(i, m));
                // update size
                this.size++;
            }
        }
    }


    /**
     * Copy constructor. It is unnecessary to verify the primality of the numbers in the list.
     *
     * @param pf
     */
    public PrimeFactorization(PrimeFactorization pf) {
        this.init();
        this.value = pf.value();

        for (PrimeFactor pFactor : pf) {
            // copy node
            this.link(this.tail, new Node(pFactor));
        }
        this.size = pf.size();
    }

    /**
     * Constructs a factorization from an array of prime factors.  Useful when the number is
     * too large to be represented even as a long integer.
     *
     * @param pfList
     */
    public PrimeFactorization(PrimeFactor[] pfList) {
        this.init();
        Node[] nodes = new Node[pfList.length];
        this.size = pfList.length;

        for (int i = 0; i < pfList.length; i++) {
            PrimeFactor primeFactor = pfList[i];
            nodes[i] = new Node(primeFactor);
        }
        for (Node node : nodes) {
            this.link(this.tail.previous, node);
        }
        // recalculate the value
        this.updateValue();
    }


    // --------------
    // Primality Test
    // --------------

    /**
     * Test if a number is a prime or not.  Check iteratively from 2 to the largest
     * integer not exceeding the square root of n to see if it divides n.
     *
     * @param n
     * @return true if n is a prime
     * false otherwise
     */
    public static boolean isPrime(long n) {
        if (n <= 1)
            return false;
        for (long i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }


    // ---------------------------
    // Multiplication and Division
    // ---------------------------

    /**
     * Multiplies the integer v represented by this object with another number n.  Note that v may
     * be too large (in which case this.value == OVERFLOW). You can do this in one loop: Factor n and
     * traverse the doubly linked list simultaneously. For details refer to Section 3.1 in the
     * project description. Store the prime factorization of the product. Update value and size.
     *
     * @param n
     * @throws IllegalArgumentException if n < 1
     */
    public void multiply(long n) throws IllegalArgumentException {
        if (n < 1) {
            throw new IllegalArgumentException();
        }
        this.multiply(new PrimeFactorization(n));
    }

    /**
     * Multiplies the represented integer v with another number in the factorization form.  Traverse both
     * linked lists and store the result in this list object.  See Section 3.1 in the project description
     * for details of algorithm.
     *
     * @param pf
     */
    public void multiply(PrimeFactorization pf) {
        PrimeFactorizationIterator iteratorThis = this.iterator();
        PrimeFactorizationIterator iteratorThat = pf.iterator();
        while (iteratorThis.hasNext() && iteratorThat.hasNext()) {
            PrimeFactor pFactorThis = iteratorThis.next();
            PrimeFactor pFactorThat = iteratorThat.next();
            if (pFactorThis.prime == pFactorThat.prime) {
                pFactorThis.multiplicity += pFactorThat.multiplicity;
            } else {
                iteratorThis.add(pFactorThat.clone());
            }
        }
        while (iteratorThat.hasNext()) {
            PrimeFactor pFactor = iteratorThat.next();
            iteratorThis.add(pFactor);
        }
        this.updateValue();
    }


    /**
     * Multiplies the integers represented by two PrimeFactorization objects.
     *
     * @param pf1
     * @param pf2
     * @return object of PrimeFactorization to represent the product
     */
    public static PrimeFactorization multiply(PrimeFactorization pf1, PrimeFactorization pf2) {
        PrimeFactorization clone = new PrimeFactorization(pf1);
        clone.multiply(pf2);
        return clone;
    }


    /**
     * Divides the represented integer v by n.  Make updates to the list, value, size if divisible.
     * No update otherwise. Refer to Section 3.2 in the project description for details.
     *
     * @param n
     * @return true if divisible
     * false if not divisible
     * @throws IllegalArgumentException if n <= 0
     */
    public boolean dividedBy(long n) throws IllegalArgumentException {
        if (this.value() != -1 && this.value() < n) {
            return false;
        }
        return this.dividedBy(new PrimeFactorization(n));
    }


    /**
     * Division where the divisor is represented in the factorization form.  Update the linked
     * list of this object accordingly by removing those nodes housing prime factors that disappear
     * after the division.  No update if this number is not divisible by pf. Algorithm details are
     * given in Section 3.2.
     *
     * @param pf
     * @return true if divisible by pf
     * false otherwise
     */
    public boolean dividedBy(PrimeFactorization pf) {
        if (this.value() != -1) {
            if (pf.value() != -1 && this.value() < pf.value()) {
                return false;
            }
            if (pf.value() == -1) {
                return false;
            }
        }
        if (this.value() == pf.value()) {
            this.clearList();
            this.updateValue();
            return true;
        }
        PrimeFactorization clone = new PrimeFactorization(this);
        PrimeFactorizationIterator iterCopy = clone.iterator();
        for (PrimeFactor pFactorPf : pf) {
            while (iterCopy.hasNext()) {
                PrimeFactor pFactorCopy = iterCopy.next();
                if (pFactorCopy.prime > pFactorPf.prime) {
                    return false;
                } else if (pFactorCopy.prime == pFactorPf.prime) {
                    if (pFactorCopy.multiplicity < pFactorPf.multiplicity) {
                        return false;
                    } else if (pFactorCopy.multiplicity > pFactorPf.multiplicity) {
                        pFactorCopy.multiplicity -= pFactorPf.multiplicity;
                        break;
                    } else {
                        iterCopy.remove();
                        break;
                    }
                }
            }
        }
        this.head = clone.head;
        this.tail = clone.tail;
        this.size = clone.size();
        this.updateValue();
        return true;
    }


    /**
     * Divide the integer represented by the object pf1 by that represented by the object pf2.
     * Return a new object representing the quotient if divisible. Do not make changes to pf1 and
     * pf2. No update if the first number is not divisible by the second one.
     *
     * @param pf1
     * @param pf2
     * @return quotient as a new PrimeFactorization object if divisible
     * null otherwise
     */
    public static PrimeFactorization dividedBy(PrimeFactorization pf1, PrimeFactorization pf2) {
        PrimeFactorization clone = new PrimeFactorization(pf1);
        clone.dividedBy(pf2);
        return clone;
    }


    // -------------------------------------------------
    // Greatest Common Divisor and Least Common Multiple
    // -------------------------------------------------

    /**
     * Computes the greatest common divisor (gcd) of the represented integer v and an input integer n.
     * Returns the result as a PrimeFactor object.  Calls the method Euclidean() if
     * this.value != OVERFLOW.
     * <p>
     * It is more efficient to factorize the gcd than n, which can be much greater.
     *
     * @param n
     * @return prime factorization of gcd
     * @throws IllegalArgumentException if n < 1
     */
    public PrimeFactorization gcd(long n) throws IllegalArgumentException {
        long value = Euclidean(this.value(), n);
        return new PrimeFactorization(value);
    }


    /**
     * Implements the Euclidean algorithm to compute the gcd of two natural numbers m and n.
     * The algorithm is described in Section 4.1 of the project description.
     *
     * @param m
     * @param n
     * @return gcd of m and n.
     * @throws IllegalArgumentException if m < 1 or n < 1
     */
    public static long Euclidean(long m, long n) throws IllegalArgumentException {
        if (m < 1 || n < 1) {
            throw new IllegalArgumentException();
        }
        while (n != 0) {
            long temp = n;
            n = m % n;
            m = temp;
        }
        return m;
    }


    /**
     * Computes the gcd of the values represented by this object and pf by traversing the two lists.  No
     * direct computation involving value and pf.value. Refer to Section 4.2 in the project description
     * on how to proceed.
     *
     * @param pf
     * @return prime factorization of the gcd
     */
    public PrimeFactorization gcd(PrimeFactorization pf) {
        PrimeFactorizationIterator iterator = this.iterator();
        PrimeFactorizationIterator iteratorPf = pf.iterator();
        ArrayList<PrimeFactor> list = new ArrayList<PrimeFactor>();
        while (iterator.hasNext() && iteratorPf.hasNext()) {
            PrimeFactor pFactor = iterator.next();
            PrimeFactor pFactorPf = iteratorPf.next();
            if (pFactor.prime == pFactorPf.prime) {
                list.add(new PrimeFactor(pFactor.prime, Math.min(pFactor.multiplicity, pFactorPf.multiplicity)));
            }
        }
        return new PrimeFactorization(list.toArray(new PrimeFactor[0]));
    }


    /**
     * @param pf1
     * @param pf2
     * @return prime factorization of the gcd of two numbers represented by pf1 and pf2
     */
    public static PrimeFactorization gcd(PrimeFactorization pf1, PrimeFactorization pf2) {
        PrimeFactorization clone = new PrimeFactorization(pf1);
        return clone.gcd(pf2);
    }


    /**
     * Computes the least common multiple (lcm) of the two integers represented by this object
     * and pf.  The list-based algorithm is given in Section 4.3 in the project description.
     *
     * @param pf
     * @return factored least common multiple
     */
    public PrimeFactorization lcm(PrimeFactorization pf) {
        PrimeFactorizationIterator iterator = this.iterator();
        PrimeFactorizationIterator iteratorPf = pf.iterator();
        PrimeFactorization newPf = new PrimeFactorization();
        PrimeFactorizationIterator newIterator = newPf.iterator();
        while (iterator.hasNext() && iteratorPf.hasNext()) {
            PrimeFactor pFactor = iterator.next();
            PrimeFactor pFactorPf = iteratorPf.next();
            if (pFactor.prime == pFactorPf.prime) {
                newIterator.add(new PrimeFactor(pFactor.prime, Math.max(pFactor.multiplicity, pFactorPf.multiplicity)));
            } else {
                if (pFactor.prime < pFactorPf.prime) {
                    newIterator.add(pFactor.clone());
                    newIterator.add(pFactorPf.clone());
                } else {
                    newIterator.add(pFactorPf.clone());
                    newIterator.add(pFactor.clone());
                }
            }
        }
        while (iterator.hasNext()) {
            newIterator.add(iterator.next().clone());
        }
        while (iteratorPf.hasNext()) {
            newIterator.add(iteratorPf.next().clone());
        }
        return newPf;
    }


    /**
     * Computes the least common multiple of the represented integer v and an integer n. Construct a
     * PrimeFactors object using n and then call the lcm() method above.  Calls the first lcm() method.
     *
     * @param n
     * @return factored least common multiple
     * @throws IllegalArgumentException if n < 1
     */
    public PrimeFactorization lcm(long n) throws IllegalArgumentException {
        if (n < 1) {
            throw new IllegalArgumentException();
        }
        return this.lcm(new PrimeFactorization(n));
    }

    /**
     * Computes the least common multiple of the integers represented by pf1 and pf2.
     *
     * @param pf1
     * @param pf2
     * @return prime factorization of the lcm of two numbers represented by pf1 and pf2
     */
    public static PrimeFactorization lcm(PrimeFactorization pf1, PrimeFactorization pf2) {
        PrimeFactorization clone = new PrimeFactorization(pf1);
        return clone.lcm(pf2);
    }


    // ------------
    // List Methods
    // ------------

    /**
     * Traverses the list to determine if p is a prime factor.
     * <p>
     * Precondition: p is a prime.
     *
     * @param p
     * @return true  if p is a prime factor of the number v represented by this linked list
     * false otherwise
     * @throws IllegalArgumentException if p is not a prime
     */
    public boolean containsPrimeFactor(int p) throws IllegalArgumentException {
        if (!isPrime(p)) {
            throw new IllegalArgumentException();
        }
        for (PrimeFactor pFactor : this) {
            if (pFactor.prime == p) {
                return true;
            } else if (pFactor.prime > p) {
                return false;
            }
        }
        return false;
    }

    // The next two methods ought to be private but are made public for testing purpose. Keep
    // them public

    /**
     * Adds a prime factor p of multiplicity m.  Search for p in the linked list.  If p is found at
     * a node N, add m to N.multiplicity.  Otherwise, create a new node to store p and m.
     * <p>
     * Precondition: p is a prime.
     *
     * @param p prime
     * @param m multiplicity
     * @return true  if m >= 1
     * false if m < 1
     */
    public boolean add(int p, int m) {
        if (m < 1) {
            return false;
        }
        // m >= 1
        PrimeFactorizationIterator iterator = this.iterator();
        while (iterator.hasNext()) {
            PrimeFactor primeFactor = iterator.next();
            if (primeFactor.prime > p) {
                iterator.add(new PrimeFactor(p, m));
            } else if (primeFactor.prime == p) {
                primeFactor.multiplicity += m;
            }
        }
        this.updateValue();
        return true;
    }


    /**
     * Removes m from the multiplicity of a prime p on the linked list.  It starts by searching
     * for p.  Returns false if p is not found, and true if p is found. In the latter case, let
     * N be the node that stores p. If N.multiplicity > m, subtracts m from N.multiplicity.
     * If N.multiplicity <= m, removes the node N.
     * <p>
     * Precondition: p is a prime.
     *
     * @param p
     * @param m
     * @return true  when p is found.
     * false when p is not found.
     * @throws IllegalArgumentException if m < 1
     */
    public boolean remove(int p, int m) throws IllegalArgumentException {
        if (m < 1) {
            throw new IllegalArgumentException();
        }
        PrimeFactorizationIterator iterator = this.iterator();
        while (iterator.hasNext()) {
            PrimeFactor pFactor = iterator.next();
            if (pFactor.prime == p) {
                if (pFactor.multiplicity > m) {
                    pFactor.multiplicity -= m;
                } else {
                    iterator.remove();
                }
                this.updateValue();
                return true;
            }
        }
        return false;
    }


    /**
     * @return size of the list
     */
    public int size() {
        return this.size;
    }


    /**
     * Writes out the list as a factorization in the form of a product. Represents exponentiation
     * by a caret.  For example, if the number is 5814, the returned string would be printed out
     * as "2 * 3^2 * 17 * 19".
     */
    @Override
    public String toString() {
        Node node = this.head.next;
        StringBuilder result = new StringBuilder();
        while (node != this.tail) {
            String part = node.toString();
            result.append(String.format("%s", part));
            if (node.next != this.tail) {
                // has next node
                result.append("*");
            }
            node = node.next;
        }
        return result.toString();
    }


    // The next three methods are for testing, but you may use them as you like.

    /**
     * @return true if this PrimeFactorization is representing a value that is too large to be within
     * long's range. e.g. 999^999. false otherwise.
     */
    public boolean valueOverflow() {
        return value == OVERFLOW;
    }

    /**
     * @return value represented by this PrimeFactorization, or -1 if valueOverflow()
     */
    public long value() {
        return value;
    }


    public PrimeFactor[] toArray() {
        PrimeFactor[] arr = new PrimeFactor[size];
        int i = 0;
        for (PrimeFactor pf : this)
            arr[i++] = pf;
        return arr;
    }


    @Override
    public PrimeFactorizationIterator iterator() {
        return new PrimeFactorizationIterator();
    }

    /**
     * Doubly-linked node type for this class.
     */
    private class Node {
        public PrimeFactor pFactor;            // prime factor
        public Node next;
        public Node previous;

        /**
         * Default constructor for creating a dummy node.
         */
        public Node() {
            this.pFactor = null;
            this.next = null;
            this.previous = null;
        }

        /**
         * Precondition: p is a prime
         *
         * @param p prime number
         * @param m multiplicity
         * @throws IllegalArgumentException if m < 1
         */
        public Node(int p, int m) throws IllegalArgumentException {
            this.pFactor = new PrimeFactor(p, m);
            this.next = null;
            this.previous = null;
        }


        /**
         * Constructs a node over a provided PrimeFactor object.
         *
         * @param pf
         * @throws IllegalArgumentException
         */
        public Node(PrimeFactor pf) {
            this.pFactor = pf;
            this.next = null;
            this.previous = null;
        }


        /**
         * Printed out in the form: prime + "^" + multiplicity.  For instance "2^3".
         * Also, deal with the case pFactor == null in which a string "dummy" is
         * returned instead.
         */
        @Override
        public String toString() {
            if (this.pFactor == null) {
                return "dummy";
            } else {
                return this.pFactor.toString();
            }
        }
    }


    private class PrimeFactorizationIterator implements ListIterator<PrimeFactor> {
        // Class invariants: 
        // 1) logical cursor position is always between cursor.previous and cursor
        // 2) after a call to next(), cursor.previous refers to the node just returned 
        // 3) after a call to previous() cursor refers to the node just returned 
        // 4) index is always the logical index of node pointed to by cursor

        private Node cursor = head.next;
        private Node pending = null;    // node pending for removal
        private int index = 0;

        // other instance variables ...


        /**
         * Default constructor positions the cursor before the smallest prime factor.
         */
        public PrimeFactorizationIterator() {

        }

        @Override
        public boolean hasNext() {
            return this.nextIndex() < size();
        }


        @Override
        public boolean hasPrevious() {
            return this.previousIndex() > size();
        }


        @Override
        public PrimeFactor next() {
            if (!this.hasNext()) {
                return null;
            }
            this.pending = this.cursor;
            this.cursor = this.cursor.next;
            this.index++;
            return this.pending.pFactor;
        }


        @Override
        public PrimeFactor previous() {
            if (!this.hasPrevious()) {
                return null;
            }
            this.pending = this.cursor;
            this.cursor = this.cursor.previous;
            this.index--;
            return this.pending.pFactor;
        }


        /**
         * Removes the prime factor returned by next() or previous()
         *
         * @throws IllegalStateException if pending == null
         */
        @Override
        public void remove() throws IllegalStateException {
            if (this.pending == null) {
                throw new IllegalArgumentException();
            }
            // remove node
            unlink(this.pending);
            index--;
            size--;
        }


        /**
         * Adds a prime factor at the cursor position.  The cursor is at a wrong position
         * in either of the two situations below:
         * <p>
         * a) pf.prime < cursor.previous.pFactor.prime if cursor.previous != head.
         * b) pf.prime > cursor.pFactor.prime if cursor != tail.
         * <p>
         * Take into account the possibility that pf.prime == cursor.pFactor.prime.
         * <p>
         * Precondition: pf.prime is a prime.
         *
         * @param pf
         * @throws IllegalArgumentException if the cursor is at a wrong position.
         */
        @Override
        public void add(PrimeFactor pf) throws IllegalArgumentException {
            // check error condition
            if (this.cursor.previous != head) {
                if (pf.prime < this.cursor.previous.pFactor.prime) {
                    throw new IllegalArgumentException();
                }
            } else if (this.cursor != tail) {
                if (pf.prime > this.cursor.pFactor.prime) {
                    throw new IllegalArgumentException();
                }
            }
            if (this.cursor.pFactor != null && pf.prime == this.cursor.pFactor.prime) {
                this.cursor.pFactor.multiplicity += pf.multiplicity;
            } else {
                // link after the cursor
                link(cursor.previous, new Node(pf));
                size++;
            }
            updateValue();
        }


        @Override
        public int nextIndex() {
            return index;
        }


        @Override
        public int previousIndex() {
            return index - 1;
        }

        @Deprecated
        @Override
        public void set(PrimeFactor pf) {
            throw new UnsupportedOperationException(getClass().getSimpleName() + " does not support set method");
        }

        // Other methods you may want to add or override that could possibly facilitate
        // other operations, for instance, addition, access to the previous element, etc.
        //
        // ...
        //
    }


    // --------------
    // Helper methods 
    // --------------

    private void init() {
        // default value
        this.value = 1;

        // node list
        this.head = new Node();
        this.tail = new Node();
        this.head.previous = null;
        this.head.next = this.tail;
        this.tail.previous = this.head;
        this.tail.next = null;

        // size of nodes
        this.size = 0;
    }

    /**
     * Inserts toAdd into the list after current without updating size.
     * <p>
     * Precondition: current != null, toAdd != null
     */
    private void link(Node current, Node toAdd) {
        Node node = this.head;
        while (node != null) {
            if (node == current) {
                if (node == this.tail) {
                    // if tail, insert after previous of the tail.
                    node = this.tail.previous;
                }
                node.next.previous = toAdd;
                toAdd.previous = node;
                toAdd.next = node.next;
                node.next = toAdd;
                return;
            }
            node = node.next;
        }
    }


    /**
     * Removes toRemove from the list without updating size.
     */
    private void unlink(Node toRemove) {
        Node node = this.head;
        while (node != this.tail) {
            if (node == toRemove) {
                // remove node
                node.previous.next = node.next;
                node.next.previous = node.previous;
                return;
            }
            // next node
            node = node.next;
        }
    }


    /**
     * Remove all the nodes in the linked list except the two dummy nodes.
     * <p>
     * Made public for testing purpose.  Ought to be private otherwise.
     */
    public void clearList() {
        Node node = this.head.next;
        while (node != this.tail) {
            this.unlink(node);
            node = node.next;
        }
        this.size = 0;
    }

    /**
     * Multiply the prime factors (with multiplicities) out to obtain the represented integer.
     * Use Math.multiply(). If an exception is throw, assign OVERFLOW to the instance variable value.
     * Otherwise, assign the multiplication result to the variable.
     */
    private void updateValue() {
        long sumValue = 1;
        try {
            PrimeFactorizationIterator iterator = this.iterator();
            while (iterator.hasNext()) {
                PrimeFactor pFactor = iterator.next();
                long value = (long) Math.pow(pFactor.prime, pFactor.multiplicity);
                sumValue = Math.multiplyExact(sumValue, value);
            }
            this.value = sumValue;
        } catch (ArithmeticException e) {
            value = OVERFLOW;
        }
    }
}
