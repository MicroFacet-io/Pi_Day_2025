public class Sayantan_pi_day {
    // Function to compute π using the continued fraction expansion
    public static double computePi(int depth) {
        // The sequence of denominators in the continued fraction
        int[] denominators = {7, 15, 1, 292, 1, 1, 1, 2, 1, 3, 1, 14, 2, 1, 1, 2}; // More terms give better accuracy
        
        double fraction = 0.0;
        
        // Start from the last term and work backward
        for (int i = Math.min(depth, denominators.length) - 1; i >= 0; i--) {
            fraction = 1.0 / (denominators[i] + fraction);
        }
        
        // The final approximation of π
        return 3 + fraction;
    }

    public static void main(String[] args) {
        int depth = 10;  // Increase for better accuracy
        double approxPi = computePi(depth);
        
        System.out.println("Approximated value of π using Continued Fraction: " + approxPi);
    }
}
