/**
 * Created by LEOLEOl on 5/7/2017.
 */
public class Utilities {
    static  public void printData(int[] data, int k)
    {
        for (int i = 1; i <= k; ++i) System.out.printf("%d ", data[i]);
    }

    static public void printData(char[] data, int k)
    {
        for (int i = 1; i <= k; ++i) System.out.printf("%c ", data[i]);
    }

    static public void reverse(int[] x, int p1, int p2)
    {
        while (p1 < p2) {
            int t = x[p1];
            x[p1] = x[p2];
            x[p2] = t;
            p1++;
            p2--;
        }
    }
}
