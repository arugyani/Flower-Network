package main.network;

import java.util.Random;
import java.util.concurrent.ThreadLocalRandom;

public class Functions {
    // Activation Functions
    public double sigmoid(double x) {
        return 1/(1+Math.exp(-x));
    }
    public double tanh(double x) {return Math.tanh(x);}

    // Activation Function Derivatives
    public double sigmoid_derivative(double x) {
        return sigmoid(x) * (1 -  sigmoid(x));
    }
    public double tanh_derivative(double x) {return (1 - square(tanh(x)));}

    // Square Values
    public double square(double a) {return a*a;}

    // Shuffle Arrays
    public double[][] shuffle(double[][] arr) {
        Random rnd = ThreadLocalRandom.current();

        for(int i = arr.length - 1; i > 0; i--) {
            int index = rnd.nextInt(i + 1);
            double[] a = arr[index];
            arr[index] = arr[i];
            arr[i] = a;
        }

        return arr;
    }
}
