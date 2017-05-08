import java.util.ArrayList;

/**
 * Created by LEOLEOl on 5/7/2017.
 */
public class Arrangement {
    static int[] getNextArrangement(int[] data, int[] x, int n, int k)
    {
        int[] temp;
        if ((temp = Permutation.getNextPermutation(data, x, k)) == null) {
            Utilities.reverse(x, 1, k); // Đảo ngược mảng
            return Combination.getNextCombination(data, x, n, k);
        }
        else return temp;
    }

    static char[] getNextArrangement(char[] data, int[] x, int n, int k)
    {
        char[] temp;
        if ((temp = Permutation.getNextPermutation(data, x, k)) == null) {
            Utilities.reverse(x, 1, k); // Đảo ngược mảng
            return Combination.getNextCombination(data, x, n, k);
        }
        else return temp;
    }

    public void doCharArrangement(int n, int k)
    {
        int[] x = new int[k + 1];
        char[] data = new char[n + 1];
        for (int i = 1; i <= k; ++i) x[i] = i;// Cau hinh khoi tao
        for (int i = 1; i <= n; ++i) data[i] = (char) (65 + i - 1);

        char[] temp = data.clone();
        int c = 0;
        while (temp != null) {
            System.out.printf("%d. ", ++c);
            Utilities.printData(temp, k);
            System.out.printf("\n");
            temp = getNextArrangement(data, x, n, k);
        }
    }

    public void doIntArrangement(int n, int k)
    {
        int[] x = new int[k + 1];
        int[] data = new int[n + 1];
        for (int i = 1; i <= k; ++i) x[i] = i;// Cau hinh khoi tao
        for (int i = 1; i <= n; ++i) data[i] = i;

        int[] temp = data.clone();
        int c = 0;
        while (temp != null) {
            System.out.printf("%d. ", ++c);
            Utilities.printData(temp, k);
            System.out.printf("\n");
            temp = getNextArrangement(data, x, n, k);
        }
    }

    public static void main(String[] args)
    {
        Arrangement test = new Arrangement();
        test.doCharArrangement(5, 3);
        // Git Java asdfasdf
    }
}
