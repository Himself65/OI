package edu.iastate.cs228.hw1;

public class Main {
    public static void main(String[] args) {
        // 9 7 11 3 6 2 1 10 5
        Point[] points = new Point[]{
                new Point(9, 0),
                new Point(7, 0),
                new Point(11, 0),
                new Point(3, 0),
                new Point(6, 0),
                new Point(2, 0),
                new Point(1, 0),
                new Point(10, 0),
                new Point(5, 0)
        };
        PointScanner scanner = new PointScanner(points, Algorithm.MergeSort);
        scanner.scan();

    }
}
