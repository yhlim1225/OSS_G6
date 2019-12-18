// The MIT License (MIT)

// Copyright (c) 2019 OSS_G6. All rights reserved.

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef RQUERY_H_INCLUDED
#define RQUERY_H_INCLUDED

#include<vector>

template<typename T>
class SegTree{
protected:
    std::vector<T> tree; // Segment Tree
    int base; // to indicate number of non-leaf nodes
    int range; // to check the range of the index
    T (*oper)(T,T); // merge function pointer
    T id_elem; // identity element
    T _get_value(int st, int fn, int ns, int nf, int num);
public:
    //sz = number of leaf node
    //id = identity element
    //fnc = function pointer for merge function
    SegTree(int sz, T id, T (*fnc)(T,T));
    void update(int idx, T val); // update value
    T get_value(int st, int fn); // wrapper function of _get_value
};

/*
constructor of Segment Tree which needs followings
minimum number of leaf nodes = sz
identity element for merging operation = id
function pointer of merging operation = fnc
*/
template<typename T>
SegTree<T>::SegTree(int sz, T id, T (*fnc)(T,T)){
    id_elem=id;
    oper=fnc;
    range=sz;
    base=1;
    while(base<sz) base<<=1;
    tree.resize(base*2+2);
    for(int i=0 ; i<base*2+2 ; i++) tree[i]=id_elem;
    base--;
}

/*
To prevent modifying value of ns, nf, num, make this function as protected
*/
template<typename T>
T SegTree<T>::_get_value(int st, int fn, int ns, int nf, int num){
    if(nf==-1) nf=base+1;
    if(nf<st || fn<ns) return id_elem;
    if(st<=ns && nf<=fn) return tree[num];
    int mid=(ns+nf)>>1;
    T val1=SegTree<T>::_get_value(st,fn,ns,mid,num*2);
    T val2=SegTree<T>::_get_value(st,fn,mid+1,nf,num*2+1);
    return oper(val1,val2);
}

/*
To get the value from st to fn
This function is wrapper function of _get_value
*/
template<typename T>
T SegTree<T>::get_value(int st, int fn){
    if(1<=st && st<=fn && fn<=range){
        T ret=SegTree<T>::_get_value(st,fn,1,-1,1);
        return ret;
    }
    //if range is out of bound, then function returns identity element
    return id_elem;
}

/*
Updating the Segment Tree at idx by val
*/
template<typename T>
void SegTree<T>::update(int idx, T val){
    //update occur only when idx is not out of bound
    if(1<=idx && idx<=range){
        idx+=base;
        tree[idx]=val;
        idx>>=1;
        while(idx!=0){
            tree[idx]=oper(tree[idx*2],tree[idx*2+1]);
            idx>>=1;
        }
    }
}

#endif // RQUERY_H_INCLUDED
