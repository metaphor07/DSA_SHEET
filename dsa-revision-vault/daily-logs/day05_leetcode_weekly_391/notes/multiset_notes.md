# Multiset Notes

A multiset is a sorted bag.

Example:

multiset<int> st;
st.insert(5);
st.insert(2);
st.insert(5);
st.insert(9);

Internally:

{2, 5, 5, 9}

Important operations:

*st.begin()   -> smallest value
*st.rbegin()  -> largest value

st.erase(st.find(value));

This removes only one occurrence of `value`.

Do not use:

st.erase(value);

because it removes all occurrences of that value.

In Q4, duplicate values of x+y or x-y can exist, so erase(find(value)) is necessary.
