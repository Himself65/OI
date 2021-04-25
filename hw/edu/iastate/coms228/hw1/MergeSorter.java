package edu.iastate.cs228.hw1;

import java.io.FileNotFoundException;
import java.lang.NumberFormatException;
import java.lang.IllegalArgumentException;
import java.util.InputMismatchException;

/**
 *
 */

/**
 * This class implements the mergesort algorithm.
 */

public class MergeSorter extends AbstractSorter {
    /**
     * Constructor takes an array of points.  It invokes the superclass constructor, and also
     * set the instance variables algorithm in the superclass.
     *
     * @param pts   input array of integers
     */
    public MergeSorter(Point[] pts) {
        super(pts);
        this.algorithm = "MergeSort";
    }


    /**
     * Perform mergesort on the array points[] of the parent class AbstractSorter.
     */
    @Override
    public void sort() {
        this.mergeSortRec(this.points);
    }


    /**
     * This is a recursive method that carries out mergesort on an array pts[] of points. One
     * way is to make copies of the two halves of pts[], recursively call mergeSort on them,
     * and merge the two sorted subarrays into pts[].
     *
     * @param pts point array
     */
    private void mergeSortRec(Point[] pts) {
        if (pts.length < 2) {
            return;
        }
        int mid = pts.length / 2;
        Point[] leftPts = new Point[mid];
        System.arraycopy(pts, 0, leftPts, 0, leftPts.length);
        Point[] rightPts = new Point[pts.length - mid];
        System.arraycopy(pts, mid, rightPts, 0, rightPts.length);
        mergeSortRec(leftPts);
        mergeSortRec(rightPts);
        merge(pts, leftPts, rightPts);
    }

    private void merge(Point[] pts, Point[] leftPts, Point[] rightPts) {
        int left = leftPts.length;
        int right = rightPts.length;
        int i = 0, j = 0, k = 0;
        while (i < left && j < right) {
            pts[k++] = (leftPts[i].compareTo(rightPts[j]) < 0) ? leftPts[i++] : rightPts[j++];
        }
        while (i < left) {
            pts[k++] = leftPts[i++];
        }
        while (j < right) {
            pts[k++] = rightPts[j++];
        }
    }
}
