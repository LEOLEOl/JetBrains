import javafx.util.Pair;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Hashtable;
import java.util.Scanner;

/**
 * Created by LEOLEOl on 5/10/2017.
 */
public class Floyd {
    int size_max =  100;
    int maxC = 10000;

    int[][] matrix;
    int[][] Trace;

    Hashtable<Pair, Double> hashtableMatrix;
    Hashtable<Pair, Double> traceHashtable;

    int n;

    Floyd()
    {
        matrix = new int[size_max][size_max];
        Trace = new int[size_max][size_max];

        hashtableMatrix = new Hashtable<>();
        traceHashtable = new Hashtable<>();
    }

    public void loadGraph(String file_path)
    {
        try (BufferedReader br = new BufferedReader(new FileReader(file_path))) {
            String line = br.readLine();
            Scanner scanner = new Scanner(line);
            n = scanner.nextInt();

            // Init matrix
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    if (i == j) {
                        matrix[i][j] = 0;
                        hashtableMatrix.put(new Pair(i, j), new Double(0));
                    }
                    else {
                        matrix[i][j] = maxC;
                        hashtableMatrix.put(new Pair(i, j), new Double(maxC));
                    }

            while ((line = br.readLine()) != null) {
                scanner = new Scanner(line);
                int a = scanner.nextInt();
                int b = scanner.nextInt();
                int c = scanner.nextInt();

                matrix[a][b] = c;
                hashtableMatrix.put(new Pair(a, b), new Double(c));

                // process the line.
                System.out.printf("%d %d %d\n", a, b, c);

            }
        }
        catch (IOException e)
        {

        }
    }

    public void Floyd()
    {
        for (int u = 1; u <= n; ++u)
            for (int v = 1; v <= n; ++v)
                Trace[u][v] = v;

        for (int k = 1; k <= n; ++k)
            for (int u = 1; u <= n; ++u)
                for (int v = 1; v <= n; ++v)
                    if (matrix[u][v] > matrix[u][k] + matrix[k][v]) {
                        matrix[u][v] = matrix[u][k] + matrix[k][v];
                        Trace[u][v] = Trace[u][k];
                    }
    }

    public void printResult(int s, int f)
    {
        if (matrix[s][f] == maxC)
            System.out.printf("There is no path from %d to %d", s, f);
        else {
            System.out.printf("Distance from %d to %d: %d\n", s, f, matrix[s][f]);
            do {
                System.out.printf("%d -> ", s);
                s = Trace[s][f];
            } while (s != f);
            System.out.printf("%d\n", f);
        }
    }


    public static void main(String[] args)
    {
        Floyd floyd = new Floyd();
        floyd.loadGraph("E:/data.txt");
        floyd.Floyd();
        floyd.printResult(1, 4);
    }

}
