/**
 * Created by LEOLEOl on 5/7/2017.
 */
public class Permutation {
    static public int[] nextPermutation(int[] x, int n) {
        int i, k;

        i = n - 1;
        while (i > 0 & x[i] > x[i + 1]) --i;
        if (i > 0) { // Chưa gặp phải hoán vị cuối cùng
            k = n;// x[k] là phần từ cuối dãy
            while (x[k] < x[i]) --k; // Lùi dần k để tìm được x[k] đầu tiên lớn hơn x[i]
            int temp = x[k];
            x[k] = x[i];
            x[i] = temp;
            Utilities.reverse(x, i + 1, n);// Lât ngược đoạn cuối
        } 
        else return null;
        return x;
    }

    static public char[] getNextPermutation(char[] data, int[] x, int n)
    {
        char[] ret = null;
        x = nextPermutation(x, n);
        if (x != null) {
            ret = new char[n + 1];
            for (int i = 1; i <= n; ++i) ret[i] = data[x[i]];
        }
        return ret;
    }

    static public int[] getNextPermutation(int[] data, int[] x, int n)
    {
        int[] ret = null;
        x = nextPermutation(x, n);
        if (x != null) {
            ret = new int[n + 1];
            for (int i = 1; i <= n; ++i) ret[i] = data[x[i]];
        }
        return ret;
    }

    public void doCharPermutation(int n)
    {
	    int[] x = new int[n + 1];
	    char[] data = new char[n + 1];
        for (int i = 1; i <= n; ++i) x[i] = i; // Cau hinh dau tien
        for (int i = 1; i <= n; ++i) data[i] = (char)(65 + i - 1); // Data dau tien
	    char[] temp = data.clone();

	    int c = 0;
        while (temp != null) {
            System.out.printf("%d. ", ++c);
            Utilities.printData(temp, n);
            System.out.printf("\n");
            temp = getNextPermutation(data, x, n);
        }
    }

    public void doIntPermutation(int n)
    {
        int[] x = new int[n + 1];
        int[] data = new int[n + 1];
        for (int i = 1; i <= n; ++i) x[i] = i; // Cau hinh dau tien
        for (int i = 1; i <= n; ++i) data[i] = i; // Data dau tien
        int[] temp = data.clone();

        int c = 0;
        while (temp != null) {
            System.out.printf("%d. ", ++c);
            Utilities.printData(temp, n);
            System.out.printf("\n");
            temp = getNextPermutation(data, x, n);
        }
    }

    public static void main(String[] args)
    {
        Permutation test = new Permutation();
        test.doCharPermutation(5);
    }
}
