#ifndef LST_H
#define LST_H 1

/*
Line Search Table
线段搜索表
 */

#include <types.h>

typedef struct __lst_line_t
{
    usize left, right;
} lst_line_t;

typedef struct __lst_iterator_t
{
    lst_line_t line;
    // 这个指针是kernel/memm.h中的allocator_t *
    // 代表当前lst_line_index_t对象在allocate时使用的allocator
    // 用的话会造成递归include
    void *allocator;
    struct __lst_iterator_t *next;
} lst_iterator_t;

lst_iterator_t *lst_new(usize start, usize end);

lst_iterator_t *lst_next(lst_iterator_t *iterator);

/*
在`lst`中移除一个线段[left,right)
force=true时忽略不存在于`lst`中的线段
force=false时若有不存在于`lst`中的线段，不移除任何线段，返回false，否则返回true
 */
bool lst_remove(lst_iterator_t *lst, usize left, usize right, bool force);

/*
在`lst`中添加一个线段[left,right)
force=true时忽略已经存在于`lst`中的线段
force=false时若有存在于`lst`中的线段，只添加这些部分之外的线段，返回false，否则返回true
 */
bool lst_add(lst_iterator_t *lst, usize left, usize right, bool force);

#endif
