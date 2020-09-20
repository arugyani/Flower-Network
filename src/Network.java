import java.util.Scanner;

/**
 *
 *  THIS NETWORK DOES NOT WORK YET
 *  IT WILL MAKE YOU VERY FRUSTRATED AND ANGRY AND I REALLY DONT KNOW WHY YET
 *
 */

public class Network {
    Functions f = new Functions();
    Data d = new Data();

    public double[][] data;

    public double learningRate = 0.2;
    public double w1 = Math.random(), w2 = Math.random(), w3 = Math.random(), w4 = Math.random(), bias = Math.random();


    public void train() {
        for(int i = 0; i < 50000; i++) {
            int ri = (int) (Math.random() * data.length);
            double[] point = data[ri];

            // Weighted Average of Point's Features
            double z = point[0] * w1 + point[1] * w2 + point[2] * w3 + point[3] * w4 + bias;

            // Activation Function
            double prediction = f.sigmoid(z);

            double target = point[4];
            double cost = f.square(prediction - target);

            double dcost_pred = 2 * (prediction - target);
            double dpred_dz = f.sigmoid_derivative(z);
            double dz_dw1 = point[0];
            double dz_dw2 = point[1];
            double dz_dw3 = point[2];
            double dz_dw4 = point[3];
            double dz_db = 1;

            double dcost_dz = dcost_pred * dpred_dz;

            double dcost_dw1 = dcost_dz * dz_dw1;
            double dcost_dw2 = dcost_dz * dz_dw2;
            double dcost_dw3 = dcost_dz * dz_dw3;
            double dcost_dw4 = dcost_dz * dz_dw4;
            double dcost_db = dcost_dz * dz_db;

            w1 = w1 - learningRate * dcost_dw1;
            w2 = w2 - learningRate * dcost_dw2;
            w3 = w3 - learningRate * dcost_dw3;
            w4 = w4 - learningRate * dcost_dw4;

            bias = bias - learningRate * dcost_db;

            System.out.println("Iteration " + i + "\n\tW1: " + w1 + ", W2: " + w2 + ", W3: " + w3 + ", W4: " + w4 + "\n\tBias: " + bias + ", Cost: " + cost + "\n\tPrediction: " + prediction + ", Target: " + target);
        }
    }

    public void calculate(double sl, double sw, double pl, double pw) {
        double z = sl * w1 + sw * w2 + pl * w3 + pw * w4 + bias;
        double prediction = Math.round(f.sigmoid(z) * 2) / 2.0;
        
        if(prediction == 0) System.out.println("Iris Setosa");
        else if(prediction == 0.5) System.out.println("Iris Versicolour");
        else if(prediction == 1) System.out.println("Iris Virginica");
    }

    public void load() throws Exception {
        data = d.loadFile("res\\Iris\\iris.data");
        data = f.shuffle(data);
    }

    public static void main(String[] args) throws Exception {
        Network n = new Network();
        Scanner s = new Scanner(System.in);

        n.load();

        System.out.print("Flower Dimensions (cm):\n\tSepal Length: "); double sl = s.nextDouble();
        System.out.print("\tSepal Width: "); double sw = s.nextDouble();
        System.out.print("\tPetal Length: "); double pl = s.nextDouble();
        System.out.print("\tPetal Width: "); double pw = s.nextDouble();

        System.out.println("\nTraining...\n");
        n.train();

        n.calculate(sl, sw, pl, pw);
    }
}
