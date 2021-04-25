package edu.iastate.cs228.hw1;

import java.io.FileNotFoundException;
import java.lang.NumberFormatException;
import java.lang.IllegalArgumentException;
import java.util.InputMismatchException;


/**
 *
 */

/**
 *
 * This class implements the version of the quicksort algorithm presented in the lecture.   
 *
 */

public class QuickSorter extends AbstractSorter {
    /**
     * Constructor takes an array of points.  It invokes the superclass constructor, and also
     * set the instance variables algorithm in the superclass.
     *
     * @param pts   input array of integers
     */
    public QuickSorter(Point[] pts) {
        super(pts);
        this.algorithm = "QuickSort";
    }


    /**
     * Carry out quicksort on the array points[] of the AbstractSorter class.
     *
     */
    @Override
    public void sort() {
        this.quickSortRec(0, this.points.length - 1);
    }


    /**
     * Operates on the subarray of points[] with indices between first and last.
     *
     * @param first  starting index of the subarray
     * @param last   ending index of the subarray
     */
    private void quickSortRec(int first, int last) {
        if (first < last) {
            int p = this.partition(first, last);
            quickSortRec(first, p - 1);
            quickSortRec(p + 1, last);
        }
    }


    /**
     * Operates on the subarray of points[] with indices between first and last.
     *
     * @param first starting index of the subarray
     * @param last  ending index of the subarray
     * @return  index of pivot element
     */
    private int partition(int first, int last) {
        Point p = this.points[last];
        int i = first - 1;
        for (int j = first; j <= last - 1; j++) {
            if (this.points[j].compareTo(p) < 0) {
                i++;
                this.swap(i, j);
            }
        }
        this.swap(i + 1, last);
        return i + 1;
    }
}
