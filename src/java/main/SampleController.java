package main;

import javafx.event.ActionEvent;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.text.Text;
import main.network.Network;

public class SampleController {
    public TextField sepalWidth;
    public TextField sepalLength;
    public TextField petalWidth;
    public TextField petalLength;

    public Text prediction;

    Network n = new Network();

    public void train_weights(ActionEvent a) {
        try {
            n.load();
            n.train(100000);
            n.saveWeights("res/weights.txt");
        } catch (Exception e) {
            System.out.println("Could not load data.");
        }
    }

    public void predict(ActionEvent e) throws Exception {
        boolean weightsAvailable = true;
        for (int i = 0; i < n.getWeights().length; i++) {
            if (n.getWeights()[i] == 0.0) weightsAvailable = false;
        }

        if (weightsAvailable) {
            double sl, sw, pl, pw;

            if (sepalLength.getText().isEmpty() || sepalWidth.getText().isEmpty() || petalLength.getText().isEmpty() || petalWidth.getText().isEmpty()) {
                prediction.setText("All fields must be filled.");
            } else {
                sl = Double.valueOf(sepalLength.getText());
                sw = Double.valueOf(sepalWidth.getText());
                pl = Double.valueOf(petalLength.getText());
                pw = Double.valueOf(petalWidth.getText());

                String predict = n.calculate(sl, sw, pl, pw);
                prediction.setText(predict);
            }

        } else {
            prediction.setText("Must train weights first.");
        }
    }

    public void load_weights(ActionEvent e) throws Exception {
        n.loadWeights("res/weights.txt");
    }
}
