#include <bits/stdc++.h>

using namespace std;

typedef long long int lld;
typedef string String;

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
// addition operation of strings
string addNum(string str1, string str2)
{
    string ans = "";

    lld pointA = str1.size() - 1;
    lld pointB = str2.size() - 1;

    lld carry = 0;

    while (pointA >= 0 && pointB >= 0)
    {
        lld a = str1[pointA] - '0';
        lld b = str2[pointB] - '0';

        ans.push_back(((a + b + carry) % 10) + '0');

        carry = floor((a + b + carry) / 10);

        pointA--;
        pointB--;
    }

    while (pointA >= 0)
    {
        ans.push_back((((str1[pointA] - '0') + carry) % 10) + '0');
        carry = floor(((str1[pointA] - '0') + carry) / 10);
        pointA--;
    }

    while (pointB >= 0)
    {
        ans.push_back((((str2[pointB] - '0') + carry) % 10) + '0');
        carry = floor(((str2[pointB] - '0') + carry) / 10);
        pointB--;
    }

    if (carry)
    {
        ans.push_back('1');
    }

    reverse(ans.begin(), ans.end());

    if (ans[0] == '0')
    {
        return "0";
    }

    return ans;
}
bool isPalindrome(string str)
{
    for (lld i = 0; i < (str.size() / 2); i++)
    {
        if (str[i] != str[(str.size() - 1) - i])
        {
            return false;
        }
    }
    return true;
}

string getBinary(lld num)
{
    string ans = "";
    while (num)
    {
        if (num & 1)
        {
            ans.push_back('1');
        }
        else
        {
            ans.push_back('0');
        }
        num >>= 1;
    }

    // bellow logic will make sure that binary is 32bit
    // while (ans.size() != 32)
    // {
    //     ans.push_back('0');
    // }

    reverse(ans.begin(), ans.end());
    return ans;
}

lld getDecimal(string str)
{
    lld firstSetBitIndex = 0;
    while (true)
    {
        if (str[firstSetBitIndex] == '1')
        {
            break;
        }
        firstSetBitIndex++;
    }
    reverse(str.begin() + firstSetBitIndex, str.begin() + str.size());
    lld ans = 0, binTracker = 1;
    for (; firstSetBitIndex < str.size(); firstSetBitIndex++)
    {

        if (str[firstSetBitIndex] == '1')
        {
            ans += binTracker;
        }

        binTracker <<= 1;
    }
    return ans;
}

vector<lld> bfs(lld vertices, vector<vector<lld>> &adj, lld startNode)
{
    bool visited[vertices + 1];

    for (lld i = 0; i < (vertices + 1); i++)
    {
        visited[i] = false;
    }

    visited[startNode] = true; // <- change start vertex number

    queue<lld> q;
    q.push(startNode); // <- change start vertex number

    vector<lld> ans;

    while (!q.empty())
    {
        lld node = q.front();
        q.pop();

        ans.push_back(node);

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                visited[it] = true;
                q.push(it);
            }
        }
    }

    return ans;
}

void dfsHelper(lld node, vector<vector<lld>> &adj, bool visited[], vector<lld> &ans)
{
    visited[node] = true;
    ans.push_back(node);
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            dfsHelper(it, adj, visited, ans);
        }
    }
}
vector<lld> dfs(lld vertices, vector<vector<lld>> &adj, lld startingIndex)
{
    vector<lld> ans;

    bool visited[vertices + 1];
    for (lld i = 0; i < (vertices + 1); i++)
    {
        visited[i] = false;
    }

    dfsHelper(startingIndex, adj, visited, ans);

    return ans;
}

int main(void)
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // seive[index] = false means it's prime and uncomment the function body and call
    // seiveGenerate();

    return 0;
}
