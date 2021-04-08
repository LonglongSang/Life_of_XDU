#ifndef CLIENTMAP_H
#define CLIENTMAP_H
#include <algorithm>
#include <vector>
#include <string.h>
namespace sang
{
    template <class T,size_t N>
    class clientMap
    {
        private:
            std::vector<T> arr;
            std::vector<int> mp;
            std::vector<typename std::vector<T>::iterator> pos;
            T unbe;
            size_t cnt;
        public:
            clientMap()
            {
                arr.resize(N);
                mp.resize(N,-1);
                pos.resize(N);
                cnt=0;
            }

            int size()
            {
                return cnt;
            }
            void clear()
            {
                memset(mp.data(),-1,sizeof(int)*mp.size());
                cnt=0;
            }
            bool insert(int key,T val)
            {
                if(key>=N || key<0 || mp[key]!=-1) return false;
                if(mp[key]==-1)
                {
                    mp[key]=cnt;
                    pos[cnt++]=arr.begin()+key;
                }
                arr[key]=val;
                return true;
            }
            bool erase(int key)
            {
                if(key>=N || key<0 || mp[key]==-1) return false;
                typename std::vector<T>::iterator b=pos[cnt-1];
                std::swap(mp[key],mp[int(b-arr.begin())]);
                std::swap(pos[mp[key]],pos[mp[int(b-arr.begin())]]);
                cnt--;
                mp[key]=-1;
                return true;
            }
            T& operator[](int key)
            {
                if(key>=N || key<0)
                {
                    exit(1);
                }else if(mp[key]==-1)
                {
                    insert(key,unbe);
                }
                return arr[key];
            }
            typename std::vector<typename std::vector<T>::iterator>::iterator find(int key)
            {
                if(key>=N || key<0 || mp[key]==-1) return pos.begin()+cnt;
                return pos.begin()+mp[key];
            }
            typename std::vector<typename std::vector<T>::iterator>::iterator begin()
            {
                return pos.begin();
            }
            typename std::vector<typename std::vector<T>::iterator>::iterator end()
            {
                return pos.begin()+cnt;
            }

        public:
            class iterator
            {
                public:
                    typename std::vector<typename std::vector<T>::iterator>::iterator iter;
                    iterator();
                    iterator(const iterator& a);
                    iterator(typename std::vector<typename std::vector<T>::iterator>::iterator it);
                    iterator(T* val);
                    ~iterator();
                    
                    void operator++();
                    void operator++(int);
                    T operator*();
                    void operator=(const iterator& a);
                    bool operator==(const iterator& a);
                    bool operator==(typename std::vector<typename std::vector<T>::iterator>::iterator it);
                    bool operator!=(const iterator& a);
                    bool operator!=(typename std::vector<typename std::vector<T>::iterator>::iterator it);
                    typename std::vector<T>::iterator operator->();
                    iterator& operator=(typename std::vector<typename std::vector<T>::iterator>::iterator it);
            };
            bool erase(iterator it);
    };

    template <typename T,size_t N>
    bool clientMap<T,N>::erase(typename clientMap<T,N>::iterator it)
    {
        if(!(it.iter>=pos.begin() && it.iter<pos.begin()+cnt)) return false;
        return erase(*(it.iter)-arr.begin());
    };

    template <typename T,size_t N>
    clientMap<T,N>::iterator::iterator()
    {

    };
    template <typename T,size_t N>
    clientMap<T,N>::iterator::~iterator()
    {

    };
    template <class T,size_t N>
    clientMap<T,N>::iterator::iterator(const clientMap<T,N>::iterator& a)
    {
        this->iter=a.iter;
    };
    template <class T,size_t N>
    clientMap<T,N>::iterator::iterator(typename std::vector<typename std::vector<T>::iterator>::iterator it)
    {
        this->iter=it;
    };
    template <class T,size_t N>
    void clientMap<T,N>::iterator::operator++()
    {
        this->iter=std::next(this->iter);
    };
    template <class T,size_t N>
    void clientMap<T,N>::iterator::operator++(int)
    {
        this->iter=std::next(this->iter);
    };
    template <class T,size_t N>
    T clientMap<T,N>::iterator::operator*()
    {
        return *(*(this->iter));
    };
    template <class T,size_t N>
    void clientMap<T,N>::iterator::operator=(const clientMap<T,N>::iterator& a)
    {
        this->iter=a.iter;
    };
    template <class T,size_t N>
    bool clientMap<T,N>::iterator::operator!=(const clientMap<T,N>::iterator& a)
    {
        return this->iter!=a.iter;
    };
    template <class T,size_t N>
    bool clientMap<T,N>::iterator::operator!=(typename std::vector<typename std::vector<T>::iterator>::iterator it)
    {
        return this->iter!=it;
    }
    template <class T,size_t N>
    bool clientMap<T,N>::iterator::operator==(const clientMap<T,N>::iterator& a)
    {
        return iter==a.iter;
    };
    template <class T,size_t N>
    bool clientMap<T,N>::iterator::operator==(typename std::vector<typename std::vector<T>::iterator>::iterator it)
    {
        return this->iter==it;
    };
    template <class T,size_t N>
    typename clientMap<T,N>::iterator& clientMap<T,N>::iterator::operator=(typename std::vector<typename std::vector<T>::iterator>::iterator it)
    {
        this->iter=it;
        return *this;
    };
    template <class T,size_t N>
    typename std::vector<T>::iterator clientMap<T,N>::iterator::operator->()
    {
        return *iter;
    };
}
#endif