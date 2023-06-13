#include <bits/stdc++.h>

using namespace std;

typedef long long int lld;

lld binpowModular(lld base, lld power, lld Mod)
{
    //** Time complexity O(log(n)) **//

    // if power is odd then res = res*base and power--
    // if power if even then base = base*base and power = power/2
    // if power is zero then res will be the answer

    lld res = 1;

    while (power)
    {
        if (power % 2 == 0)
        {
            base = (base * base) % Mod;
            power /= 2;
        }
        else
        {
            res = (res * base) % Mod;
            power--;
        }
    }

    return res;
}

lld binpow(lld base, lld power)
{
    //** Time complexity O(log(n)) **//

    // if power is odd then res = res*base and power--
    // if power if even then base = base*base and power = power/2
    // if power is zero then res will be the answer

    lld res = 1;

    while (power)
    {
        if (power % 2 == 0)
        {
            base *= base;
            power /= 2;
        }
        else
        {
            res *= base;
            power--;
        }
    }

    return res;
}

bool isPrime(lld num)
{
    // Time complexity O(sqrt(n))

    if (num == 1 || (num % 2 == 0 && num != 2))
    {
        return false;
    }
    for (lld i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

template <class T>
lld binSearch(vector<T> &vec, lld left, lld right, T target)
{
    // to call binSearch<data type> (params);
    // time complexity O(log(N))
    if (left > right)
    {
        return -1;
    }
    lld mid = (left + right) / 2;
    if (vec[mid] == target)
    {
        return mid;
    }
    else if (vec[mid] > target)
    {
        return binSearch(vec, left, mid - 1, target);
    }
    else
    {
        return binSearch(vec, mid + 1, right, target);
    }
}

vector<string> subsequenceGenerator(string &str)
{
    // time complexity O(2^n * n)
    // including empty string there can be 2^n subsequences
    vector<string> allSequences;
    lld n = str.size();
    for (lld i = 0; i < (2 << (n - 1)); i++)
    {
        string res = "";
        lld trace = 0, temp;
        temp = i;
        while (temp)
        {
            if (temp & 1)
            {
                res.push_back(str[trace]);
            }
            trace++;
            temp >>= 1;
        }
        allSequences.push_back(res);
    }

    return allSequences;
}

class Graph
{
public:
    lld vertices = 0;
    vector<lld> *g;
    vector<bool> visitedG;

    Graph(lld vertices)
    {
        this->vertices = vertices;
        visitedG.assign(vertices, false);
        g = new vector<lld>[vertices + 1];
        // new keyword used for creating space for the pointer
    }

    void addEdge(lld vertex, lld edge)
    {
        g[vertex].push_back(edge);
        g[edge].push_back(vertex);
    }

    void display()
    {
        for (lld i = 1; i <= vertices; i++)
        {
            cout << i << " : ";
            for (auto val : g[i])
            {
                cout << val << " ";
            }
            cout << endl;
        }
    }

    void dfs(lld vertex)
    {
        cout << vertex << " ";
        visitedG[vertex] = true;
        for (auto v : g[vertex])
        {
            if (!visitedG[v])
            {
                dfs(v);
            }
        }
    }
};

// seive generate

// const int seiveSize = 1000001;
// bool seive[seiveSize]; // by default global array got false value
// void seiveGenerate()
// {
//     seive[0] = true;
//     seive[1] = true;
//     for (int i = 2; i * i < seiveSize; i++)
//     {
//         if (seive[i])
//         {
//             continue;
//         }
//         for (int j = i * i; j < seiveSize; j += i)
//         {
//             seive[j] = true;
//         }
//     }
// }

class BinTree
{
public:
    BinTree *left, *right;
    lld val;

    BinTree()
    {
        left = nullptr;
        right = nullptr;
    }
};
void consTructBst(BinTree *root, BinTree *currentNode)
{
    if (currentNode->val <= root->val)
    {
        if (root->left)
        {
            consTructBst(root->left, currentNode);
        }
        else
        {
            root->left = currentNode;
        }
    }
    else
    {
        if (root->right)
        {
            consTructBst(root->right, currentNode);
        }
        else
        {
            root->right = currentNode;
        }
    }
}
void preOrder(BinTree *node)
{
    if (node)
    {
        cout << " " << node->val;
        preOrder(node->left);
        preOrder(node->right);
    }
}
void inOrder(BinTree *node)
{
    if (node)
    {
        inOrder(node->left);
        cout << " " << node->val;
        inOrder(node->right);
    }
}
void postOrder(BinTree *node)
{
    if (node)
    {
        postOrder(node->left);
        postOrder(node->right);
        cout << " " << node->val;
    }
}

int main(void)
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // seiveGenerate();


    return 0;
}
