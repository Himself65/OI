package edu.iastate.cs228.hw1;

import java.io.FileNotFoundException;
import java.lang.NumberFormatException;
import java.lang.IllegalArgumentException;
import java.util.InputMismatchException;


/**
 *
 */

/**
 * This class implements selection sort.
 */

public class SelectionSorter extends AbstractSorter {
    /**
     * Constructor takes an array of points.  It invokes the superclass constructor, and also
     * set the instance variables algorithm in the superclass.
     *
     * @param pts input array of integers
     */
    public SelectionSorter(Point[] pts) {
        super(pts);
        this.algorithm = "SelectionSort";
    }


    /**
     * Apply selection sort on the array points[] of the parent class AbstractSorter.
     */
    @Override
    public void sort() {
        for (int i = 0; i < this.points.length - 1; i++) {
            int min = i;
            for (int j = i + 1; j < this.points.length; j++) {
                if (this.points[j].compareTo(this.points[min]) < 0) {
                    min = j;
                }
            }
            this.swap(i, min);
        }
    }
}
