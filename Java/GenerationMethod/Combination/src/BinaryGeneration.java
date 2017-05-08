import java.util.Arrays;

/**
 * Created by LEOLEOl on 5/7/2017.
 */
public class BinaryGeneration {
    public static void main(String[] args)
    {
        int i, n; // n la size cua so nhi phan
        n = 5;
        int[] x = new int[n + 1];
        Arrays.fill(x, 0);

        int c = 0;
        do {
            System.out.printf("%d. ", ++c);
            Utilities.printData(x, n);
            System.out.printf("\n");

            i = n; //x[i] la phan tu cuoi day, lui dan i cho toi khi gap so 0 hoac khi i = 0 thi dung
            while (i > 0 & x[i] == 1) --i;

            if (i > 0) { // Neu chua phai cau hinh 11..1
                x[i] = 1; // Thay x[i] = 1
                //memset(x + i + 1, 0, (n - i) * sizeof(x[1])); // Dat x[i+1] = x[i+2] = ... = x[n] = 0
                for (int j = i+1; j <= n; ++j) x[j] = 0;
            }
        } while (i != 0); // Het cau hinh
        // 10:00
    }
}
