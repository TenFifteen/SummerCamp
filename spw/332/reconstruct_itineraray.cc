/**
 * Problem: Given a list of airline tickets represented by pairs of
 *          departure and arrival airports [from, to], reconstruct the
 *          itinerary in order. All of the tickets belong to a man who
 *          departs from JFK. Thus, the itinerary must begin with JFK.
 *          If there are multiple valid itineraries, you should return the
 *          itinerary that has the smallest lexical order when read as a
 *          single string. For example, the itinerary ["JFK", "LGA"]
 *          has a smaller lexical order than ["JFK", "LGB"].
 *          All airports are represented by three capital letters (IATA code).
 *          You may assume all tickets form at least one valid itinerary.
 * Solve: construct a graph use multiset to satisfy the lexical order.
 *        use a stack to perform dfs.
 *        insert the node when all its neighbors have been visited. Then reverse
 *        the sequence.
 *        Using this way we can play one touch drawing game.
 * Tips: no
 */
vector<string> findItinerary(vector<pair<string, string>> tickets) {
    unordered_map<string, multiset<string>> adj;

    for (pair<string, string> t : tickets) {
        adj[t.first].insert(t.second);
    }

    stack<string> s;
    s.push("JFK");

    vector<string> ans;
    while (!s.empty()) {
        string now = s.top();

        if (adj[now].size() == 0) {
            ans.push_back(now);
            s.pop();
        } else {
            s.push(*(adj[now].begin()));
            adj[now].erase(adj[now].begin());
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
