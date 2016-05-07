/**
 * Problem: In data structure Hash, hash function is used to convert a string(or any other type)
 *          into an integer smaller than hash size and bigger or equal to zero. The objective of
 *          designing a hash function is to "hash" the key as unreasonable as possible. A good
 *          hash function can avoid collision as less as possible. A widely used hash function
 *          algorithm is using a magic number 33,
 * Solve: just do it
 * Tips: the magic and ans must mod HASH_SIZE before multiplication
 */
class Solution {
    public:
        /**
         * @param key: A String you should hash
         * @param HASH_SIZE: An integer
         * @return an integer
         */
        int hashCode(string key,int HASH_SIZE) {
            int n = key.size();

            long long ans = 0;
            long long magic = 1, m = 33;
            for (int i = n-1; i >= 0; --i) {
                ans = (ans + (long long)key[i] * magic % HASH_SIZE) % HASH_SIZE;
                magic = magic * m % HASH_SIZE;
            }

            return ans;
        }
};
