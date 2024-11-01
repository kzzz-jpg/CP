#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

const int MAXN = 100001;

int cnt = 0;
int head = 0;
int key[MAXN];
int height[MAXN];
int leftChild[MAXN];
int rightChild[MAXN];
int key_count[MAXN];
int sz[MAXN];

void up(int i) {
    sz[i] = sz[leftChild[i]] + sz[rightChild[i]] + key_count[i];
    height[i] = max(height[leftChild[i]], height[rightChild[i]]) + 1;
}

int leftRotate(int i) {
    int r = rightChild[i];
    rightChild[i] = leftChild[r];
    leftChild[r] = i;
    up(i);
    up(r);
    return r;
}

int rightRotate(int i) {
    int l = leftChild[i];
    leftChild[i] = rightChild[l];
    rightChild[l] = i;
    up(i);
    up(l);
    return l;
}

int maintain(int i) {
    int lh = height[leftChild[i]];
    int rh = height[rightChild[i]];
    if (lh - rh > 1) {
        if (height[leftChild[leftChild[i]]] >= height[rightChild[leftChild[i]]]) {
            i = rightRotate(i);
        } else {
            leftChild[i] = leftRotate(leftChild[i]);
            i = rightRotate(i);
        }
    } else if (rh - lh > 1) {
        if (height[rightChild[rightChild[i]]] >= height[leftChild[rightChild[i]]]) {
            i = leftRotate(i);
        } else {
            rightChild[i] = rightRotate(rightChild[i]);
            i = leftRotate(i);
        }
    }
    return i;
}

int addNode(int i, int num) {
    if (i == 0) {
        key[++cnt] = num;
        key_count[cnt] = sz[cnt] = height[cnt] = 1;
        return cnt;
    }
    if (key[i] == num) {
        key_count[i]++;
    } else if (key[i] > num) {
        leftChild[i] = addNode(leftChild[i], num);
    } else {
        rightChild[i] = addNode(rightChild[i], num);
    }
    up(i);
    return maintain(i);
}

void add(int num) {
    head = addNode(head, num);
}

int getRank(int i, int num) {
    if (i == 0) {
        return 0;
    }
    if (key[i] >= num) {
        return getRank(leftChild[i], num);
    } else {
        return sz[leftChild[i]] + key_count[i] + getRank(rightChild[i], num);
    }
}

int getRank(int num) {
    return getRank(head, num) + 1;
}

int removeMostLeft(int i, int mostLeft) {
    if (i == mostLeft) {
        return rightChild[i];
    } else {
        leftChild[i] = removeMostLeft(leftChild[i], mostLeft);
        up(i);
        return maintain(i);
    }
}

int removeNode(int i, int num) {
    if (key[i] < num) {
        rightChild[i] = removeNode(rightChild[i], num);
    } else if (key[i] > num) {
        leftChild[i] = removeNode(leftChild[i], num);
    } else {
        if (key_count[i] > 1) {
            key_count[i]--;
        } else {
            if (leftChild[i] == 0 && rightChild[i] == 0) {
                return 0;
            } else if (leftChild[i] != 0 && rightChild[i] == 0) {
                i = leftChild[i];
            } else if (leftChild[i] == 0 && rightChild[i] != 0) {
                i = rightChild[i];
            } else {
                int mostLeft = rightChild[i];
                while (leftChild[mostLeft] != 0) {
                    mostLeft = leftChild[mostLeft];
                }
                rightChild[i] = removeMostLeft(rightChild[i], mostLeft);
                leftChild[mostLeft] = leftChild[i];
                rightChild[mostLeft] = rightChild[i];
                i = mostLeft;
            }
        }
    }
    up(i);
    return maintain(i);
}

void remove(int num) {
    if (getRank(num) != getRank(num + 1)) {
        head = removeNode(head, num);
    }
}

int getIndex(int i, int x) {
    if (sz[leftChild[i]] >= x) {
        return getIndex(leftChild[i], x);
    } else if (sz[leftChild[i]] + key_count[i] < x) {
        return getIndex(rightChild[i], x - sz[leftChild[i]] - key_count[i]);
    }
    return key[i];
}

int getIndex(int x) {
    return getIndex(head, x);
}

int pre(int i, int num) {
    if (i == 0) {
        return INT_MIN;
    }
    if (key[i] >= num) {
        return pre(leftChild[i], num);
    } else {
        return max(key[i], pre(rightChild[i], num));
    }
}

int pre(int num) {
    return pre(head, num);
}

int post(int i, int num) {
    if (i == 0) {
        return INT_MAX;
    }
    if (key[i] <= num) {
        return post(rightChild[i], num);
    } else {
        return min(key[i], post(leftChild[i], num));
    }
}

int post(int num) {
    return post(head, num);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1, op, x; i <= n; i++) {
        cin >> op >> x;
        if (op == 1) {
            add(x);
        } else if (op == 2) {
            remove(x);
        } else if (op == 3) {
            cout << getRank(x) << endl;
        } else if (op == 4) {
            cout << getIndex(x) << endl;
        } else if (op == 5) {
            cout << pre(x) << endl;
        } else {
            cout << post(x) << endl;
        }
    }
    return 0;
}
