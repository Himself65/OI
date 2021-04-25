package edu.iastate.cs228.hw1;

import java.io.FileNotFoundException;
import java.lang.NumberFormatException;
import java.lang.IllegalArgumentException;
import java.util.InputMismatchException;


/**
 *
 */

/**
 * This class implements insertion sort.
 */

public class InsertionSorter extends AbstractSorter {
    // Other private instance variables if you need ...

    /**
     * Constructor takes an array of points.  It invokes the superclass constructor, and also
     * set the instance variables algorithm in the superclass.
     *
     * @param pts   input array of integers
     */
    public InsertionSorter(Point[] pts) {
        super(pts);
        this.algorithm = "InsertionSort";
    }


    /**
     * Perform insertion sort on the array points[] of the parent class AbstractSorter.
     */
    @Override
    public void sort() {
        int len = this.points.length;
        for (int j = 1; j < len; j++) {
            Point point = this.points[j];
            int i = j - 1;
            while ((i >= 0) && (this.points[i].compareTo(point) >= 0)) {
                this.points[i + 1] = this.points[i];
                i--;
            }
            this.points[i + 1] = point;
        }
    }
}
