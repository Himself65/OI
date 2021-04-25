package edu.iastate.cs228.hw1;

/**
 *
 * <p>
 * <p>
 * This class executes four sorting algorithms: selection sort, insertion sort, mergesort, and
 * quicksort, over randomly generated integers as well integers from a file input. It compares the
 * execution times of these algorithms on the same input.
 * <p>
 * <p>
 * This class executes four sorting algorithms: selection sort, insertion sort, mergesort, and
 * quicksort, over randomly generated integers as well integers from a file input. It compares the
 * execution times of these algorithms on the same input.
 */

/**
 *
 * This class executes four sorting algorithms: selection sort, insertion sort, mergesort, and
 * quicksort, over randomly generated integers as well integers from a file input. It compares the 
 * execution times of these algorithms on the same input. 
 *
 */

import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Random;


public class CompareSorters {
    /**
     * Repeatedly take integer sequences either randomly generated or read from files.
     * Use them as coordinates to construct points.  Scan these points with respect to their
     * median coordinate point four times, each time using a different sorting algorithm.
     *
     * @param args
     **/
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(System.in);

        System.out.println("Performances of Four Sorting Algorithms in Point Scanning");
        System.out.println();

        System.out.println("keys:  1 (random integers)  2 (file input)  3 (exit)");
        int trial = 1;
        int key = sc.nextInt();
        while (key != 3) {
            System.out.println("Trial " + trial + ": " + key);
            trial++;
            String fileName = null;
            int numPts = 0;
            if (key == 2) {
                fileName = sc.next();
                System.out.println("Points from a file");
                System.out.println("File name: " + fileName);
            } else if (key == 1) {
                numPts = sc.nextInt();
                System.out.println("Enter number of random points: " + numPts);
            }
            System.out.println();
            System.out.println("algorithm   size  time (ns)");

            // start table
            System.out.println("----------------------------------");
            if (key == 1) {
                Point[] pts = generateRandomPoints(numPts, new Random());
                runScanners(pts);
            } else if (key == 2) {
                runScanners(fileName);
            }
            System.out.println("----------------------------------");
            System.out.println();
            // end table

            // nextKey
            key = sc.nextInt();
        }
    }

    private static void runScanners(String fileName) throws FileNotFoundException {
        PointScanner[] pointScanner = new PointScanner[4];
        for (int i = 0; i < Algorithm.values().length; i++) {
            pointScanner[i] = new PointScanner(fileName, Algorithm.values()[i]);
            pointScanner[i].scan();
            System.out.println(pointScanner[i].stats());
        }
    }

    private static void runScanners(Point[] points) {
        PointScanner[] pointScanner = new PointScanner[4];
        for (int i = 0; i < Algorithm.values().length; i++) {
            pointScanner[i] = new PointScanner(points, Algorithm.values()[i]);
            pointScanner[i].scan();
            System.out.println(pointScanner[i].stats());
        }
    }


    /**
     * This method generates a given number of random points.
     * The coordinates of these points are pseudo-random numbers within the range
     * [-50,50] 锟� [-50,50]. Please refer to Section 3 on how such points can be generated.
     *
     * Ought to be private. Made public for testing.
     *
     * @param numPts    number of points
     * @param rand      Random object to allow seeding of the random number generator
     * @throws IllegalArgumentException if numPts < 1
     */
    public static Point[] generateRandomPoints(int numPts, Random rand) throws IllegalArgumentException {
        if (numPts < 1) {
            throw new IllegalArgumentException();
        }
        Point[] pts = new Point[numPts];
        for (int i = 0; i < numPts; i++) {
            int x = rand.nextInt(101) - 50;
            int y = rand.nextInt(101) - 50;
            pts[i] = new Point(x, y);
        }
        return pts;
    }

}
