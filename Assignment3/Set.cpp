

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

class Set
{
    vector<int> set;

public:
    Set() {}
    Set(vector<int> s) : set(s) {}
    void display();
    Set Union(Set s);
    Set Intersection(Set s);
    Set Complement(Set s);
    Set SetDifference(Set s);
    bool TestEqualSets(Set s);
    void PrintCartesianProduct(Set s);
    void DisplayPowerSet();
    bool TestDistinct();
    void FindMeanVarianceStandardDeviationMedian();
};

void Set::display()
{
    cout << "{ ";
    for (int i = 0; i < set.size(); i++)
    {
        cout << set[i];
        if (i != set.size() - 1)
            cout << ", ";
    }
    cout << " }" << endl;
}

Set Set::Union(Set s)
{
    vector<int> result;
    for (int i = 0; i < set.size(); i++)
        result.push_back(set[i]);
    for (int i = 0; i < s.set.size(); i++)
    {
        if (find(result.begin(), result.end(), s.set[i]) == result.end())
            result.push_back(s.set[i]);
    }
    return Set(result);
}

Set Set::Intersection(Set s)
{
    vector<int> result;
    for (int i = 0; i < set.size(); i++)
    {
        if (find(s.set.begin(), s.set.end(), set[i]) != s.set.end())
            result.push_back(set[i]);
    }
    return Set(result);
}

Set Set::Complement(Set s)
{
    vector<int> result;
    for (int i = 0; i < set.size(); i++)
    {
        if (find(s.set.begin(), s.set.end(), set[i]) == s.set.end())
            result.push_back(set[i]);
    }
    return Set(result);
}

Set Set::SetDifference(Set s)
{
    vector<int> result;
    for (int i = 0; i < set.size(); i++)
    {
        if (find(s.set.begin(), s.set.end(), set[i]) == s.set.end())
            result.push_back(set[i]);
    }
    return Set(result);
}

bool Set::TestEqualSets(Set s)
{
    if (set.size() != s.set.size())
        return false;
    for (int i = 0; i < set.size(); i++)
    {
        if (find(s.set.begin(), s.set.end(), set[i]) == s.set.end())
            return false;
    }
    return true;
}

void Set::PrintCartesianProduct(Set s)
{
    cout << "{ ";
    for (int i = 0; i < set.size(); i++)
    {
        for (int j = 0; j < s.set.size(); j++)
        {
            cout << "(" << set[i] << ", " << s.set[j] << ")";
            if (i != set.size() - 1 || j != s.set.size() - 1)
                cout << ", ";
        }
    }
    cout << " }" << endl;
}

void Set::DisplayPowerSet()
{
    int n = set.size();
    int powerSetSize = pow(2, n);
    for (int i = 0; i < powerSetSize; i++)
    {
        cout << "{ ";
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                cout << set[j] << " ";
        }
        cout << "}" << endl;
    }
}

bool Set::TestDistinct()
{
    for (int i = 0; i < set.size(); i++)
    {
        for (int j = i + 1; j < set.size(); j++)
        {
            if (set[i] == set[j])
                return false;
        }
    }
    return true;
}

void Set::FindMeanVarianceStandardDeviationMedian()
{
    int n = set.size();
    double mean = accumulate(set.begin(), set.end(), 0) / (double)n;
    double variance = 0;
    for (int i = 0; i < n; i++)
        variance += pow(set[i] - mean, 2);
    variance /= n;
    double standardDeviation = sqrt(variance);
    sort(set.begin(), set.end());
    double median;
    if (n % 2 == 0)
        median = (set[n / 2 - 1] + set[n / 2]) / 2.0;
    else
        median = set[n / 2];
    cout << "Mean: " << mean << endl;
    cout << "Variance: " << variance << endl;
    cout << "Standard Deviation: " << standardDeviation << endl;
    cout << "Median: " << median << endl;
}

int main()
{
    vector<int> s1 = {1, 2, 3, 4, 5};
    vector<int> s2 = {3, 4, 5, 6, 7};
    Set set1(s1);
    Set set2(s2);
    cout << "Set 1: ";
    set1.display();
    cout << "Set 2: ";
    set2.display();
    cout << "Union: ";
    set1.Union(set2).display();
    cout << "Intersection: ";
    set1.Intersection(set2).display();
    cout << "Complement of Set 1 with respect to Set 2: ";
    set1.Complement(set2).display();
    cout << "Set Difference of Set 1 with respect to Set 2: ";
    set1.SetDifference(set2).display();
    cout << "Are Set 1 and Set 2 equal? " << (set1.TestEqualSets(set2) ? "Yes" : "No") << endl;
    cout << "Cartesian Product of Set 1 and Set 2: ";
    set1.PrintCartesianProduct(set2);
    cout << "Power Set of Set 1: " << endl;
    set1.DisplayPowerSet();
    cout << "Is Set 1 distinct? " << (set1.TestDistinct() ? "Yes" : "No") << endl;
    cout << "Mean, Variance, Standard Deviation, and Median of Set 1: " << endl;
    set1.FindMeanVarianceStandardDeviationMedian();
    return 0;
}