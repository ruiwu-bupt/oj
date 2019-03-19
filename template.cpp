#include <bits/stdc++.h>
using namesapce std;

// 二分搜索 第一个等于
int searchLow(vector<int>& nums,int target){
		int low = 0, high = nums.size()-1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid;
        }
        return nums[low] == target ? low : -1;
}
// 二分搜索 最后一个等于
int searchHigh(vector<int>& nums,int target){
      int low = 0, high = nums.size()-1;
      while (low < high - 1) {
          int mid = low + (high - low) / 2;
          if (nums[mid] > target)
              high = mid - 1;
          else
              low = mid;
      }
      return nums[high] == target ? high : (nums[low] == target ? low : -1);
}
// 最大公约数 最小公倍数
int gcd(int a, int b) {
        if (b == 0) return a;
        if (a < b) return gcd(b, a);
        else return gcd(a % b, b);
    }
int lcm(int a, int b) {
    return a * b / gcd(a,b);
}

//线段树
class segmentTree {
public:
    struct node{
        int sum;
        int l;
        int r;
        node *lp, *rp;
        node(int b, int c, int d, node* lp=NULL, node* rp=NULL) : sum(b), l(c), r(d),lp(lp), rp(rp){}
    };

    node* root;
    vector<int> nums;

    NumArray(vector<int> nums) {
        root = build(nums, 0, nums.size()-1);
        this.nums = nums;
    }

    void update(int i, int val) {
        node* tmp = root;
        while (tmp) {
            tmp->sum += (val-nums[i]);
            int mid = tmp->l + (tmp->r - tmp->l)/2;
            if (i <= mid)
                tmp = tmp->lp;
            else
                tmp = tmp->rp;
        }
        nums[i] = val;
    }

    int sumRange(int i, int j) {
        return __range_sum(root, i, j);
    }
private:
    node* build(vector<int> &nums, int l, int r) {
        if (l > r)
            return NULL;
        if (l == r)
            return new node(nums[l], l, r);
        int mid = l + (r-l)/2;
        node* lp = build(nums, l, mid);
        node* rp = build(nums, mid+1, r);
        node* root = new node(lp->sum+rp->sum, l, r, lp, rp);
        return root;
    }

    int __range_sum(node* root, int i, int j) {
        if (i == root->l && j == root->r)
            return root->sum;
        int mid = root->l + (root->r - root->l)/2;
        if (mid < i)
            return __range_sum(root->rp, i, j);
        else if (mid >= j)
            return __range_sum(root->lp, i, j);
        else
            return __range_sum(root->lp, i, mid) + assist(root->rp, mid+1, j);
    }
};

class unionFind {
public:

}
