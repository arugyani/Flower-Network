import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.nio.file.attribute.UserDefinedFileAttributeView;
import java.util.ArrayList;

public class Data {
    public double[][] loadFile(String url) throws Exception {
        ArrayList<String[]> arr = new ArrayList<>();

        File file = new File(url);
        BufferedReader br = new BufferedReader(new FileReader(file));

        String st;
        while((st = br.readLine()) != null) {
            arr.add(st.split("\\,"));
        }

        double[][] conv = new double[arr.size()][5];

        for(int i = 0; i < arr.size(); i++) {
            conv[i][0] = Double.valueOf(arr.get(i)[0]);
            conv[i][1] = Double.valueOf(arr.get(i)[1]);
            conv[i][2] = Double.valueOf(arr.get(i)[2]);
            conv[i][3] = Double.valueOf(arr.get(i)[3]);

            if(arr.get(i)[4].equals("Iris-setosa")) conv[i][4] = 0.0;
            else if(arr.get(i)[4].equals("Iris-versicolor")) conv[i][4] = 0.5;
            else if (arr.get(i)[4].equals("Iris-virginica")) conv[i][4] = 1.0;
        }

        return conv;
    }
}
