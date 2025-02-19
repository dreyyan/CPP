#include <deque>
#include <list>
#include <set>
#include <vector>
#include <iomanip>
#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace chrono;

int main() {
    /* Vector, Deque, List, Set */
    // [1] VECTOR
    vector<int> vec;
    cout << setw(34) << "[ TIME TABLE ]\n";
    cout << setw(48) << "[ VECTOR ]\n";

    // Time: Adding Elements (push_back)
    auto start = high_resolution_clock::now();
    for (int i = 0; i < 100000; ++i) {
        vec.push_back(i);
    } auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    // Display
    cout << setw(34) << "+ 100,000 Elements (push_back): " << duration.count() << " microseconds\n";

    // Time: Removing Elements (pop_back)
    start = high_resolution_clock::now();
    for (int i = 0; i < 50000; ++i) {
        vec.pop_back();
    } end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    // Display
    cout << setw(34) << "- 50,000 Elements (pop_back): " << duration.count() << " microseconds\n";

    // Time: Iteration
    start = high_resolution_clock::now();
    for (const auto& num : vec) {
        // Iterate over the remaining elements
        int x = num;
    } end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    // Display
    cout << setw(34) << "* 50,000 Elements: " << duration.count() << " microseconds\n";

    // Time: Insert Element at Beginning
    start = high_resolution_clock::now();
    vec.insert(vec.begin(), 42);  // Insert an element at the beginning
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    // Display
    cout << setw(34) << "+ Element at Beginning: " << duration.count() << " microseconds\n";

    // Time: Remove Element at Beginning (erase)
    start = high_resolution_clock::now();
    vec.erase(vec.begin());  // Remove the first element
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    // Display
    cout << setw(34) << "- Element from Beginning: " << duration.count() << " microseconds\n";

    // [2] DEQUE
    deque<int> deq;
    cout << setw(34) << "[ TIME TABLE ]\n";
    cout << setw(47) << "[ DEQUE ]\n";

    // Time: Adding Elements (push_back)
    start = high_resolution_clock::now();
    for (int i = 0; i < 100000; ++i) {
        deq.push_back(i);
    }end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    // Display
    cout << setw(34) << "+ 100,000 Elements (push_back): " << duration.count() << " microseconds\n";

    // Time: Removing Elements (pop_back)
    start = high_resolution_clock::now();
    for (int i = 0; i < 50000; ++i) {
        deq.pop_back();
    } end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    // Display
    cout << setw(34) << "- 50,000 Elements (pop_back): " << duration.count() << " microseconds\n";

    // Time: Iteration
    start = high_resolution_clock::now();
    for (const auto& num : deq) {
        // Iterate over the remaining elements
        int x = num;
    } end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    // Display
    cout << setw(34) << "* 50,000 Elements: " << duration.count() << " microseconds\n";

    // Time: Insert Element at Beginning
    start = high_resolution_clock::now();
    deq.insert(deq.begin(), 42);  // Insert an element at the beginning
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    // Display
    cout << setw(34) << "+ Element at Beginning: " << duration.count() << " microseconds\n";

    // Time: Remove Element at Beginning (erase)
    start = high_resolution_clock::now();
    deq.erase(deq.begin());  // Remove the first element
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    // Display
    cout << setw(34) << "- Element from Beginning: " << duration.count() << " microseconds\n";

    // [3] LIST
    list<int> ls;
    cout << setw(34) << "[ TIME TABLE ]\n";
    cout << setw(46) << "[ LIST ]\n";

    // Time: Adding Elements (push_back)
    start = high_resolution_clock::now();
    for (int i = 0; i < 100000; ++i) {
        ls.push_back(i);
    }end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    // Display
    cout << setw(34) << "+ 100,000 Elements (push_back): " << duration.count() << " microseconds\n";

    // Time: Removing Elements (pop_back)
    start = high_resolution_clock::now();
    for (int i = 0; i < 50000; ++i) {
        ls.pop_back();
    } end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    // Display
    cout << setw(34) << "- 50,000 Elements (pop_back): " << duration.count() << " microseconds\n";

    // Time: Iteration
    start = high_resolution_clock::now();
    for (const auto& num : ls) {
        // Iterate over the remaining elements
        int x = num;
    } end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    // Display
    cout << setw(34) << "* 50,000 Elements: " << duration.count() << " microseconds\n";

    // Time: Insert Element at Beginning
    start = high_resolution_clock::now();
    ls.insert(ls.begin(), 42);  // Insert an element at the beginning
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    // Display
    cout << setw(34) << "+ Element at Beginning: " << duration.count() << " microseconds\n";

    // Time: Remove Element at Beginning (erase)
    start = high_resolution_clock::now();
    ls.erase(ls.begin());  // Remove the first element
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    // Display
    cout << setw(34) << "- Element from Beginning: " << duration.count() << " microseconds\n";

    // [4] SET
    set<int> st;
    cout << setw(34) << "[ TIME TABLE ]\n";
    cout << setw(46) << "[ SET ]\n";

    // Time: Adding Elements (push_back)
    start = high_resolution_clock::now();
    for (int i = 0; i < 100000; ++i) {
        st.insert(i);
    }end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    // Display
    cout << setw(34) << "+ 100,000 Elements (push_back): " << duration.count() << " microseconds\n";

    // Time: Removing Elements (pop_back)
    start = high_resolution_clock::now();
    for (int i = 0; i < 50000; ++i) {
        st.erase(i);
    } end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    // Display
    cout << setw(34) << "- 50,000 Elements (pop_back): " << duration.count() << " microseconds\n";

    // Time: Iteration
    start = high_resolution_clock::now();
    for (const auto& num : st) {
        // Iterate over the remaining elements
        int x = num;
    } end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    // Display
    cout << setw(34) << "* 50,000 Elements: " << duration.count() << " microseconds\n";

    // Time: Insert Element at Beginning
    start = high_resolution_clock::now();
    st.insert(st.begin(), 42);  // Insert an element at the beginning
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    // Display
    cout << setw(34) << "+ Element at Beginning: " << duration.count() << " microseconds\n";

    // Time: Remove Element at Beginning (erase)
    start = high_resolution_clock::now();
    st.erase(st.begin());  // Remove the first element
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    // Display
    cout << setw(34) << "- Element from Beginning: " << duration.count() << " microseconds\n";
    getc(stdin);
    return 0;
}