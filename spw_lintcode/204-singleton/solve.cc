/**
 * Problem:  implement a getInstance method for given class, return
 *           the same instance of this class every time you call this method.
 * Solve: singleton
 * Tips: no
 */
class Solution {
    private static Solution instance = null;
    private Solution() {}
    private static Object mutex = new Object();


    /**
     ** @return: The same instance of this class every time
     **/
    public static Solution getInstance() {
        if (instance == null) {
            synchronized(mutex) {
                if (instance == null) {
                    instance = new Solution();
                }
            }
        }

        return instance;

    }

};
