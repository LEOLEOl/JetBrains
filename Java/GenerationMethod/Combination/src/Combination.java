/**
 * Created by LEOLEOl on 5/7/2017.
 */

public class Combination {
    static public int[] nextCombination(int[] x, int n, int k)
    {
        int i = k;
        while (i > 0 & x[i] == n - k + i) --i;
        if (i > 0) {
            ++x[i];
            for (int j = i + 1; j <= k; ++j) x[j] = x[j - 1] + 1;
        }
        else return null;
        return x;
    }

    static public char[] getNextCombination(char[] data, int[] x, int n, int k)
    {
        char[] ret = null;
        x = nextCombination(x, n, k);
        if (x != null) {
            ret = new char[k+1];
            for(int i = 1; i <= k; ++i) ret[i] = data[x[i]];
        }
        return ret;
    }

    static public int[] getNextCombination(int[] data, int[] x, int n, int k)
    {
        int[] ret = null;
        x = nextCombination(x, n, k);
        if (x != null) {
            ret = new int[k+1];
            for (int i = 1; i <= k; ++i) ret[i] = data[x[i]];
        }
        return ret;
    }

    public void doCharCombination(int n, int k)
    {
        int[] x = new int[k+1];
        char[] data = new char[n+1];
        for (int i = 1; i <= k; ++i) x[i] = i;
        for (int i = 1; i <= n; ++i) data[i] = (char)(65+i-1);

        char[] temp = data.clone();

        int c = 0;
        while (temp != null) {
            System.out.printf("%d. ", ++c);
            Utilities.printData(temp, k);
            System.out.printf("\n");
            temp = getNextCombination(data, x, n, k);
        }
    }

    public void doIntCombination(int n, int k)
    {
        int[] x = new int[k+1];
        int[] data = new int[n+1];
        for (int i = 1; i <= k; ++i) x[i] = i;
        for (int i = 1; i <= n; ++i) data[i] = i;

        int[] temp = data.clone();

        int c = 0;
        while (temp != null) {
            System.out.printf("%d. ", ++c);
            Utilities.printData(temp, k);
            System.out.printf("\n");
            temp = getNextCombination(data, x, n, k);
        }
    }

    public static void main(String[] args)
    {
        Combination test = new Combination();
        test.doCharCombination(5, 3);
    }
}
