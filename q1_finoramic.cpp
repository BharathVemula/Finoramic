/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 void findpaths(vector<vector<int>> &v,vector<int >&tempVector,TreeNode* root,int sum,int fsum)
{
	if(root==NULL) return;

	if(root->left==NULL && root->right==NULL)
	{
		sum=sum+root->val;
		
		if(sum==fsum)
		{
			tempVector.push_back(root->val);
			v.push_back(tempVector);
			tempVector.pop_back();
		}
		return;

	}
	
	sum=sum+root->val;
	tempVector.push_back(root->val);
	findpaths(v,tempVector,root->left,sum,fsum);
	findpaths(v,tempVector,root->right,sum,fsum);
	tempVector.pop_back();
}
vector<vector<int> > Solution::pathSum(TreeNode* root, int sum) {

    vector<vector<int>> v; //The vector that stores that answers paths
	vector<int> tempVector;	//temp vector which stores the temporary paths
	findpaths(v,tempVector,root,0,sum); //util functions that finds all the paths
	return v;    
}