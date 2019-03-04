class NumArray {
private:
    vector<int> nums;
public:
    NumArray(vector<int> &nums) {
        this->nums.push_back(0);
        for (int num: nums) {
            this->nums.push_back(this->nums.back() + num);
        }
    }

    int sumRange(int i, int j) {
        return nums[j + 1] - nums[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
