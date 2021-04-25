package edu.iastate.cs228.hw1;

/**
 *
 */

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;


/**
 *
 * This class sorts all the points in an array of 2D points to determine a reference point whose x and y 
 * coordinates are respectively the medians of the x and y coordinates of the original points. 
 *
 * It records the employed sorting algorithm as well as the sorting time for comparison. 
 *
 */
public class PointScanner {
    protected String outputFileName;

    private Point[] points;

    private Point medianCoordinatePoint;  // point whose x and y coordinates are respectively the medians of
    // the x coordinates and y coordinates of those points in the array points[].
    private Algorithm sortingAlgorithm;
    private String algorithmName = null;

    protected long scanTime;           // execution time in nanoseconds.

    /**
     * This constructor accepts an array of points and one of the four sorting algorithms as input. Copy
     * the points into the array points[].
     *
     * @param  pts  input array of points
     * @throws IllegalArgumentException if pts == null or pts.length == 0.
     */
    public PointScanner(Point[] pts, Algorithm algo) throws IllegalArgumentException {
        if (pts == null || pts.length == 0) {
            throw new IllegalArgumentException();
        }
        this.points = pts;
        this.sortingAlgorithm = algo;
        this.medianCoordinatePoint = null;
        this.scanTime = 0;
    }


    /**
     * This constructor reads points from a file.
     *
     * @param  inputFileName    inputFileName
     * @throws FileNotFoundException    if the input file not found
     * @throws InputMismatchException   if the input file contains an odd number of integers
     */
    protected PointScanner(String inputFileName, Algorithm algo) throws FileNotFoundException, InputMismatchException {
        File file = new File(inputFileName);
        Scanner sc = new Scanner(file);
        ArrayList<Point> list = new ArrayList<Point>();
        while (sc.hasNextInt()) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            Point point = new Point(x, y);
            list.add(point);
        }
        this.points = list.toArray(new Point[0]);
        this.sortingAlgorithm = algo;
        this.medianCoordinatePoint = null;
        this.scanTime = 0;
    }


    /**
     * Carry out two rounds of sorting using the algorithm designated by sortingAlgorithm as follows:
     *
     *     a) Sort points[] by the x-coordinate to get the median x-coordinate.
     *     b) Sort points[] again by the y-coordinate to get the median y-coordinate.
     *     c) Construct medianCoordinatePoint using the obtained median x- and y-coordinates.
     *
     * Based on the value of sortingAlgorithm, create an object of SelectionSorter, InsertionSorter, MergeSorter,
     * or QuickSorter to carry out sorting.
     * @return void
     */
    public void scan() {
        Algorithm algo = this.sortingAlgorithm;
        AbstractSorter aSorter;
        if (Algorithm.SelectionSort == algo) {
            aSorter = new SelectionSorter(this.points);
        } else if (Algorithm.InsertionSort == algo) {
            aSorter = new InsertionSorter(this.points);
        } else if (Algorithm.MergeSort == algo) {
            aSorter = new MergeSorter(this.points);
        } else {
            aSorter = new QuickSorter(this.points);
        }
        this.algorithmName = aSorter.getAlgorithm();
        aSorter.setComparator(0);
        long firstStart = System.nanoTime();
        aSorter.sort();
        long firstEnd = System.nanoTime();
        int x = aSorter.getMedian().getX();
//        aSorter.setComparator(1);
//        long secondStart = System.nanoTime();
//        aSorter.sort();
//        long secondEnd = System.nanoTime();
//        int y = aSorter.getMedian().getY();
        int y = 0;
        this.medianCoordinatePoint = new Point(x, y);
//        this.scanTime = (firstEnd - firstStart) + (secondEnd - secondStart);
    }


    /**
     * Outputs performance statistics in the format:
     *
     * <sorting algorithm> <size>  <time>
     *
     * For instance,
     *
     * selection sort   1000	  9200867
     *
     * Use the spacing in the sample run in Section 2 of the project description.
     */
    public String stats() {
        String sortName = this.algorithmName;
        String size = String.valueOf(this.points.length);
        String time = String.valueOf(this.scanTime);
        return String.format("%-13s%9s  %-10s", sortName, size, time);
    }


    /**
     * Write MCP after a call to scan(),  in the format "MCP: (x, y)"   The x and y coordinates of the point are displayed on the same line with exactly one blank space
     * in between.
     */
    @Override
    public String toString() {
        String mcp = this.medianCoordinatePoint.toString();
        return String.format("MCP: %s", mcp);
    }


    /**
     *
     * This method, called after scanning, writes point data into a file by outputFileName. The format
     * of data in the file is the same as printed out from toString().  The file can help you verify
     * the full correctness of a sorting result and debug the underlying algorithm.
     *
     * @throws FileNotFoundException throws if file not found
     */
	public void writeMCPToFile() throws FileNotFoundException {
        if (this.outputFileName == null) {
            throw new FileNotFoundException();
        }
        File outputFile = new File(this.outputFileName);
        PrintWriter printWriter = new PrintWriter(outputFile);
        printWriter.printf(this.toString());
    }
}
