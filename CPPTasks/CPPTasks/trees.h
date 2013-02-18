#pragma once

#include "stdafx.h"

template<typename TData> class TreeNode 
{
private:
	TData* _data;
	TreeNode* _left;
	TreeNode* _right;
public:	
	TreeNode(const TData& data)
	{
		_data = new TData(data);
		_left = NULL;
		_right = NULL;
	}
	virtual ~TreeNode()
	{
		if (_data)
			delete _data;
		if (_left)
			delete _left;
		if (_right)
			delete _right;
	}
	const TData& Data() const
	{
		return *_data;
	}
	void SetData(const TData& data)
	{
		if (_data)
			delete _data;
		_data = new TData(data);
	}	
	void SetLeft(const TData& data)
	{
		if (_left)
			delete _left;
		_left = new TreeNode(data);
	}
	void SetRight(const TData& data)
	{
		if (_right)
			delete _right;
		_right = new TreeNode(data);
	}
	void SetLeft(const TreeNode* l)
	{
		if (_left)
			delete _left;
		_left = l;
	}
	void SetRight(const TreeNode* r)
	{
		if (_right)
			delete _right;
		_right = r;
	}
	const TreeNode* Left() const
	{
		return _left;
	}
	const TreeNode* Right() const
	{
		return _right;
	}
};

template<typename TData> TreeNode<TData>* RandomTree(int depth)
{
	TreeNode<TData>* tree = new TreeNode<TData>(rand());
	return tree;
}

