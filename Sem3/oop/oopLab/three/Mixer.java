package three;

import java.util.*;

class MixerDemo {
    Scanner sc = new Scanner(System.in);
    int arr[];

    void accept(int n) {
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
    }

    MixerDemo mix(MixerDemo B) {
        MixerDemo C = new MixerDemo();
        C.arr = new int[this.arr.length + B.arr.length];
        int i;
        int j;
        // add elements of the calling object
        for (i = 0; i < this.arr.length; i++) {
            C.arr[i] = this.arr[i];
        }
        // add elements of the parameter obj if they are not in array of A
        for (j = 0; j < B.arr.length; j++, i++) {
            int s = 0;
            for (int n = 0; n < this.arr.length; n++) {
                if (this.arr[n] == B.arr[j]) {
                    s = 1;
                    break;
                }
            }
            if (s == 0) {
                C.arr[i] = B.arr[j];
                i++; // only when adding an element
            }

        }

        // sort array of C
        for (int k = 0; k < C.arr.length; k++) {
            for (int l = 0; l < C.arr.length - k - 1; l++) {
                if (C.arr[l] > C.arr[l + 1]) {
                    int temp = C.arr[l];
                    C.arr[l] = C.arr[l + 1];
                    C.arr[l + 1] = temp;
                }
            }
        }

        // // remove duplicates from array

        // // left shift if equal
        // for (int p = 0; p < C.arr.length; p++) {
        // if (C.arr[p] == C.arr[p + 1]) {
        // for (int x = p; x < C.arr.length; x++) {
        // C.arr[x] = C.arr[x + 1];
        // }
        // }

        // }

        return C;
    }

    void display() {
        for (int i = 0; i < this.arr.length; i++) {

            if (this.arr[i] == 0) {
                continue;
            }
            System.out.println(arr[i]);
        }
    }
}

public class Mixer {
    public static void main(String[] args) {
        MixerDemo A = new MixerDemo();
        A.accept(4);
        MixerDemo B = new MixerDemo();
        B.accept(5);
        MixerDemo C = A.mix(B);
        System.out.println("C array elements: ");
        C.display();

    }
}