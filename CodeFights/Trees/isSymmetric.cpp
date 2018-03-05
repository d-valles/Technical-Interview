//
// Definition for binary tree:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
bool isCompareTree(Tree<int> *A, Tree<int> *B) {
	if(!A && !B){
		return true;
	}
	else if((!A && B) || (!B && A) || (A->value != B->value)) {
		return false;
	}

	return isCompareTree(A->left, B->right) && isCompareTree(A->right, B->left);
}

bool isTreeSymmetric(Tree<int> *t) {
	if(!t) return true;
	return isCompareTree(t->left, t->right);
}

