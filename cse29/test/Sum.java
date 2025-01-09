public class Sum {
    private static int sum(int x, int y) {
        int result = x + y;
        return result;
    }

    public static void main(String[] args) {
        int a = 1;
        int b = 2;
        int total = sum(a, b);
        System.out.println("sum of " + a + " and " + b + " = " + total);
    }
}

