module;

//#include "Poco/Foundation.h"
#include "Poco/Dynamic/Var.h"
#include "Poco/Dynamic/VarHolder.h"
#include "Poco/SharedPtr.h"
#include "Poco/OrderedMap.h"
#include "Poco/OrderedSet.h"
#include <map>
#include <set>


namespace Poco {
namespace Dynamic {


template <typename S, typename I = typename S::ConstIterator>
std::string structToString(const S& data, bool wrap = true)
/// Utility function for converting DynamicStruct to std::string.
/// Set wrap to false in order to prevent string values wrapping
/// (useful to prevent JSON fragments from being treated as strings).
{
	std::string val;
	val.append("{ ");
	I it = data.begin();
	I itEnd = data.end();
	if (!data.empty())
	{
		Var key(it->first);
		Impl::appendJSONKey(val, key);
		val.append(": ");
		Impl::appendJSONValue(val, it->second, wrap);
		++it;
	}
	for (; it != itEnd; ++it)
	{
		val.append(", ");
		Var key(it->first);
		Impl::appendJSONKey(val, key);
		val.append(": ");
		Impl::appendJSONValue(val, it->second, wrap);
	}
	val.append(" }");
	return val;
}


template <typename K, typename M = std::map<K, Var>, typename S = std::set<K>>
class Struct
	/// Struct allows to define a named collection of Var objects.
{
public:
	typedef M Data;
	typedef S NameSet;
	typedef typename Data::iterator Iterator;
	typedef typename Data::const_iterator ConstIterator;
	typedef typename Struct<K>::Data::value_type ValueType;
	typedef typename Struct<K>::Data::size_type SizeType;
	typedef typename std::pair<typename Struct<K, M, S>::Iterator, bool> InsRetVal;
	typedef typename Poco::SharedPtr<Struct<K, M, S>> Ptr;

	Struct() : _data()
		/// Creates an empty Struct
	{
	}

	Struct(const Data& val) : _data(val)
		/// Creates the Struct from the given value.
	{
	}

	template <typename T>
	Struct(const std::map<K, T>& val)
	{
		assignMap(val);
	}

	template <typename T>
	Struct(const OrderedMap<K, T>& val)
	{
		assignMap(val);
	}

	virtual ~Struct()
		/// Destroys the Struct.
	{
	}

	inline Var& operator [] (const K& name)
		/// Returns the Var with the given name, creates an entry if not found.
	{
		return _data[name];
	}

	const Var& operator [] (const K& name) const
		/// Returns the Var with the given name, throws a
		/// NotFoundException if the data member is not found.
	{
		ConstIterator it = find(name);
		if (it == end()) throw NotFoundException(name);
		return it->second;
	}

	inline bool contains(const K& name) const
		/// Returns true if the Struct contains a member with the given name
	{
		return find(name) != end();
	}

	inline Iterator find(const K& name)
		/// Returns an iterator, pointing to the <name,Var> pair containing
		/// the element, or it returns end() if the member was not found
	{
		return _data.find(name);
	}

	inline ConstIterator find(const K& name) const
		/// Returns a const iterator, pointing to the <name,Var> pair containing
		/// the element, or it returns end() if the member was not found
	{
		return _data.find(name);
	}

	inline Iterator end()
		/// Returns the end iterator for the Struct
	{
		return _data.end();
	}

	inline ConstIterator end() const
		/// Returns the end const iterator for the Struct
	{
		return _data.end();
	}

	inline Iterator begin()
		/// Returns the begin iterator for the Struct
	{
		return _data.begin();
	}

	inline ConstIterator begin() const
		/// Returns the begin const iterator for the Struct
	{
		return _data.begin();
	}

	template <typename T>
	inline InsRetVal insert(const K& key, const T& value)
		/// Inserts a <name, Var> pair into the Struct,
		/// returns a pair containing the iterator and a boolean which
		/// indicates success or not (is true, when insert succeeded, false,
		/// when already another element was present, in this case Iterator
		/// points to that other element)
	{
		// fix: SunPro C++ is silly ...
		ValueType valueType(key, value);
		return insert(valueType);
	}

	inline InsRetVal insert(const ValueType& aPair)
		/// Inserts a <name, Var> pair into the Struct,
		/// returns a pair containing the iterator and a boolean which
		/// indicates success or not (is true, when insert succeeded, false,
		/// when already another element was present, in this case Iterator
		/// points to that other element)
	{
		return _data.insert(aPair);
	}

	inline SizeType erase(const K& key)
		/// Erases the element if found, returns number of elements deleted
	{
		return _data.erase(key);
	}

	inline void erase(Iterator& it)
		/// Erases the element at the given position
	{
		_data.erase(it);
	}

	inline void clear()
		/// Remove all elements from the struct
	{
		_data.clear();
	}

	inline void swap(Struct& other) noexcept
		/// Swap content of Struct with another Struct
	{
		_data.swap(other._data);
	}

	inline bool empty() const
		/// Returns true if the Struct doesn't contain any members
	{
		return _data.empty();
	}

	SizeType size() const
		/// Returns the number of members the Struct contains
	{
		return _data.size();
	}

	inline NameSet members() const
		/// Returns a sorted collection containing all member names
	{
		NameSet keys;
		ConstIterator it = begin();
		ConstIterator itEnd = end();
		for (; it != itEnd; ++it) keys.insert(it->first);
		return keys;
	}

	inline Var getVar(const K& key) const
		/// Returns the var value of the element with the given name.
		/// Throws a NotFoundException if the key does not exist.
	{
		ConstIterator it = find(key);
		if (it == end())
		{
			throw NotFoundException("Key not found in Struct");
		}
		return it->second;
	}

	template<typename DefT = Var>
	inline Var getVar(const K& key, const DefT& defaultValue) const
		/// Returns the var value of the element with the given name.
		/// or defaultValue if none is found.
	{
		ConstIterator it = find(key);
		if (it == end())
		{
			return defaultValue;
		}
		return it->second;
	}

	std::string toString(bool wrap = true) const
		/// Returns the DynamicStruct as string.
		///
		/// To prevent unwanted string wrapping
		/// (eg. when a value is JSON string),
		/// `wrap` should be false. Note, however,
		/// that wrap argument is of a limited utility
		/// because it applies to the entire Struct,
		/// so it should not be relied on when mixed content
		/// (ie. plain string, which should be wrapped,
		/// and JSON-as-string entries, which shouldn't)
		/// is held.
	{
		return structToString<Data, ConstIterator>(_data, wrap);
	}

private:
	template <typename T>
	void assignMap(const T& map)
	{
		typedef typename T::const_iterator MapConstIterator;

		MapConstIterator it = map.begin();
		MapConstIterator end = map.end();
		for (; it != end; ++it) _data.insert(ValueType(it->first, Var(it->second)));
	}

	Data _data;
};


#if defined(POCO_OS_FAMILY_WINDOWS)

extern template class Struct<std::string>;
extern template class Struct<int>;

extern template class Struct<std::string, Poco::OrderedMap<std::string, Var>, Poco::OrderedSet<std::string>>;
extern template class Struct<int, OrderedMap<int, Var>, OrderedSet<int>>;

#else

extern template class Foundation_API Struct<std::string>;
extern template class Foundation_API Struct<int>;

extern template class Foundation_API Struct<std::string, Poco::OrderedMap<std::string, Var>, Poco::OrderedSet<std::string>>;
extern template class Foundation_API Struct<int, OrderedMap<int, Var>, OrderedSet<int>>;

#endif


template <>
class VarHolderImpl<Struct<std::string, std::map<std::string, Var>, std::set<std::string>>> : public VarHolder
{
public:
	typedef std::string KeyType;
	typedef std::map<KeyType, Var> MapType;
	typedef std::set<KeyType> SetType;
	typedef Struct<KeyType, MapType, SetType> ValueType;

	VarHolderImpl(const ValueType& val) : _val(val)
	{
	}

	~VarHolderImpl()
	{
	}

	const std::type_info& type() const
	{
		return typeid(ValueType);
	}

	void convert(Int8&) const
	{
		throw BadCastException("Cannot cast Struct type to Int8");
	}

	void convert(Int16&) const
	{
		throw BadCastException("Cannot cast Struct type to Int16");
	}

	void convert(Int32&) const
	{
		throw BadCastException("Cannot cast Struct type to Int32");
	}

	void convert(Int64&) const
	{
		throw BadCastException("Cannot cast Struct type to Int64");
	}

	void convert(UInt8&) const
	{
		throw BadCastException("Cannot cast Struct type to UInt8");
	}

	void convert(UInt16&) const
	{
		throw BadCastException("Cannot cast Struct type to UInt16");
	}

	void convert(UInt32&) const
	{
		throw BadCastException("Cannot cast Struct type to UInt32");
	}

	void convert(UInt64&) const
	{
		throw BadCastException("Cannot cast Struct type to UInt64");
	}

	void convert(bool&) const
	{
		throw BadCastException("Cannot cast Struct type to bool");
	}

	void convert(float&) const
	{
		throw BadCastException("Cannot cast Struct type to float");
	}

	void convert(double&) const
	{
		throw BadCastException("Cannot cast Struct type to double");
	}

	void convert(char&) const
	{
		throw BadCastException("Cannot cast Struct type to char");
	}

	void convert(std::string& val) const
	{
		val = structToString(_val);
	}

	void convert(Poco::DateTime&) const
	{
		throw BadCastException("Struct -> Poco::DateTime");
	}

	void convert(Poco::LocalDateTime&) const
	{
		throw BadCastException("Struct -> Poco::LocalDateTime");
	}

	void convert(Poco::Timestamp&) const
	{
		throw BadCastException("Struct -> Poco::Timestamp");
	}

	VarHolder* clone(Placeholder<VarHolder>* pVarHolder = 0) const
	{
		return cloneHolder(pVarHolder, _val);
	}

	const ValueType& value() const
	{
		return _val;
	}

	bool isArray() const
	{
		return false;
	}

	bool isStruct() const
	{
		return true;
	}

	bool isOrdered() const
	{
		return false;
	}

	bool isInteger() const
	{
		return false;
	}

	bool isSigned() const
	{
		return false;
	}

	bool isNumeric() const
	{
		return false;
	}

	bool isString() const
	{
		return false;
	}

	std::size_t size() const
	{
		return _val.size();
	}

	Var& operator [] (const KeyType& name)
	{
		return _val[name];
	}

	const Var& operator [] (const KeyType& name) const
	{
		return _val[name];
	}

private:
	ValueType _val;
};


template <>
class VarHolderImpl<Struct<int, std::map<int, Var>, std::set<int>>> : public VarHolder
{
public:
	typedef int KeyType;
	typedef std::map<KeyType, Var> MapType;
	typedef std::set<KeyType> SetType;
	typedef Struct<KeyType, MapType, SetType> ValueType;

	VarHolderImpl(const ValueType& val) : _val(val)
	{
	}

	~VarHolderImpl()
	{
	}

	const std::type_info& type() const
	{
		return typeid(ValueType);
	}

	void convert(Int8&) const
	{
		throw BadCastException("Cannot cast Struct type to Int8");
	}

	void convert(Int16&) const
	{
		throw BadCastException("Cannot cast Struct type to Int16");
	}

	void convert(Int32&) const
	{
		throw BadCastException("Cannot cast Struct type to Int32");
	}

	void convert(Int64&) const
	{
		throw BadCastException("Cannot cast Struct type to Int64");
	}

	void convert(UInt8&) const
	{
		throw BadCastException("Cannot cast Struct type to UInt8");
	}

	void convert(UInt16&) const
	{
		throw BadCastException("Cannot cast Struct type to UInt16");
	}

	void convert(UInt32&) const
	{
		throw BadCastException("Cannot cast Struct type to UInt32");
	}

	void convert(UInt64&) const
	{
		throw BadCastException("Cannot cast Struct type to UInt64");
	}

	void convert(bool&) const
	{
		throw BadCastException("Cannot cast Struct type to bool");
	}

	void convert(float&) const
	{
		throw BadCastException("Cannot cast Struct type to float");
	}

	void convert(double&) const
	{
		throw BadCastException("Cannot cast Struct type to double");
	}

	void convert(char&) const
	{
		throw BadCastException("Cannot cast Struct type to char");
	}

	void convert(std::string& val) const
	{
		val = structToString(_val);
	}

	void convert(Poco::DateTime&) const
	{
		throw BadCastException("Struct -> Poco::DateTime");
	}

	void convert(Poco::LocalDateTime&) const
	{
		throw BadCastException("Struct -> Poco::LocalDateTime");
	}

	void convert(Poco::Timestamp&) const
	{
		throw BadCastException("Struct -> Poco::Timestamp");
	}

	VarHolder* clone(Placeholder<VarHolder>* pVarHolder = 0) const
	{
		return cloneHolder(pVarHolder, _val);
	}

	const ValueType& value() const
	{
		return _val;
	}

	bool isArray() const
	{
		return false;
	}

	bool isStruct() const
	{
		return true;
	}

	bool isOrdered() const
	{
		return false;
	}

	bool isInteger() const
	{
		return false;
	}

	bool isSigned() const
	{
		return false;
	}

	bool isNumeric() const
	{
		return false;
	}

	bool isString() const
	{
		return false;
	}

	std::size_t size() const
	{
		return _val.size();
	}

	Var& operator [] (const KeyType& name)
	{
		return _val[name];
	}

	const Var& operator [] (const KeyType& name) const
	{
		return _val[name];
	}

private:
	ValueType _val;
};


template <>
class VarHolderImpl<Struct<std::string, Poco::OrderedMap<std::string, Var>, Poco::OrderedSet<std::string>>> : public VarHolder
{
public:
	typedef std::string KeyType;
	typedef Poco::OrderedMap<KeyType, Var> MapType;
	typedef Poco::OrderedSet<KeyType> SetType;
	typedef Struct<KeyType, MapType, SetType> ValueType;

	VarHolderImpl(const ValueType& val) : _val(val)
	{
	}

	~VarHolderImpl()
	{
	}

	const std::type_info& type() const
	{
		return typeid(ValueType);
	}

	void convert(Int8&) const
	{
		throw BadCastException("Cannot cast Struct type to Int8");
	}

	void convert(Int16&) const
	{
		throw BadCastException("Cannot cast Struct type to Int16");
	}

	void convert(Int32&) const
	{
		throw BadCastException("Cannot cast Struct type to Int32");
	}

	void convert(Int64&) const
	{
		throw BadCastException("Cannot cast Struct type to Int64");
	}

	void convert(UInt8&) const
	{
		throw BadCastException("Cannot cast Struct type to UInt8");
	}

	void convert(UInt16&) const
	{
		throw BadCastException("Cannot cast Struct type to UInt16");
	}

	void convert(UInt32&) const
	{
		throw BadCastException("Cannot cast Struct type to UInt32");
	}

	void convert(UInt64&) const
	{
		throw BadCastException("Cannot cast Struct type to UInt64");
	}

	void convert(bool&) const
	{
		throw BadCastException("Cannot cast Struct type to bool");
	}

	void convert(float&) const
	{
		throw BadCastException("Cannot cast Struct type to float");
	}

	void convert(double&) const
	{
		throw BadCastException("Cannot cast Struct type to double");
	}

	void convert(char&) const
	{
		throw BadCastException("Cannot cast Struct type to char");
	}

	void convert(std::string& val) const
	{
		val = structToString(_val);
	}

	void convert(Poco::DateTime&) const
	{
		throw BadCastException("Struct -> Poco::DateTime");
	}

	void convert(Poco::LocalDateTime&) const
	{
		throw BadCastException("Struct -> Poco::LocalDateTime");
	}

	void convert(Poco::Timestamp&) const
	{
		throw BadCastException("Struct -> Poco::Timestamp");
	}

	VarHolder* clone(Placeholder<VarHolder>* pVarHolder = 0) const
	{
		return cloneHolder(pVarHolder, _val);
	}

	const ValueType& value() const
	{
		return _val;
	}

	bool isArray() const
	{
		return false;
	}

	bool isStruct() const
	{
		return true;
	}

	bool isOrdered() const
	{
		return true;
	}

	bool isInteger() const
	{
		return false;
	}

	bool isSigned() const
	{
		return false;
	}

	bool isNumeric() const
	{
		return false;
	}

	bool isString() const
	{
		return false;
	}

	std::size_t size() const
	{
		return _val.size();
	}

	Var& operator [] (const KeyType& name)
	{
		return _val[name];
	}

	const Var& operator [] (const KeyType& name) const
	{
		return _val[name];
	}

private:
	ValueType _val;
};


template <>
class VarHolderImpl<Struct<int, Poco::OrderedMap<int, Var>, Poco::OrderedSet<int>>> : public VarHolder
{
public:
	typedef int KeyType;
	typedef Poco::OrderedMap<KeyType, Var> MapType;
	typedef Poco::OrderedSet<KeyType> SetType;
	typedef Struct<KeyType, MapType, SetType> ValueType;

	VarHolderImpl(const ValueType& val) : _val(val)
	{
	}

	~VarHolderImpl()
	{
	}

	const std::type_info& type() const
	{
		return typeid(ValueType);
	}

	void convert(Int8&) const
	{
		throw BadCastException("Cannot cast Struct type to Int8");
	}

	void convert(Int16&) const
	{
		throw BadCastException("Cannot cast Struct type to Int16");
	}

	void convert(Int32&) const
	{
		throw BadCastException("Cannot cast Struct type to Int32");
	}

	void convert(Int64&) const
	{
		throw BadCastException("Cannot cast Struct type to Int64");
	}

	void convert(UInt8&) const
	{
		throw BadCastException("Cannot cast Struct type to UInt8");
	}

	void convert(UInt16&) const
	{
		throw BadCastException("Cannot cast Struct type to UInt16");
	}

	void convert(UInt32&) const
	{
		throw BadCastException("Cannot cast Struct type to UInt32");
	}

	void convert(UInt64&) const
	{
		throw BadCastException("Cannot cast Struct type to UInt64");
	}

	void convert(bool&) const
	{
		throw BadCastException("Cannot cast Struct type to bool");
	}

	void convert(float&) const
	{
		throw BadCastException("Cannot cast Struct type to float");
	}

	void convert(double&) const
	{
		throw BadCastException("Cannot cast Struct type to double");
	}

	void convert(char&) const
	{
		throw BadCastException("Cannot cast Struct type to char");
	}

	void convert(std::string& val) const
	{
		val = structToString(_val);
	}

	void convert(Poco::DateTime&) const
	{
		throw BadCastException("Struct -> Poco::DateTime");
	}

	void convert(Poco::LocalDateTime&) const
	{
		throw BadCastException("Struct -> Poco::LocalDateTime");
	}

	void convert(Poco::Timestamp&) const
	{
		throw BadCastException("Struct -> Poco::Timestamp");
	}

	VarHolder* clone(Placeholder<VarHolder>* pVarHolder = 0) const
	{
		return cloneHolder(pVarHolder, _val);
	}

	const ValueType& value() const
	{
		return _val;
	}

	bool isArray() const
	{
		return false;
	}

	bool isStruct() const
	{
		return true;
	}

	bool isOrdered() const
	{
		return true;
	}

	bool isInteger() const
	{
		return false;
	}

	bool isSigned() const
	{
		return false;
	}

	bool isNumeric() const
	{
		return false;
	}

	bool isString() const
	{
		return false;
	}

	std::size_t size() const
	{
		return _val.size();
	}

	Var& operator [] (const KeyType& name)
	{
		return _val[name];
	}

	const Var& operator [] (const KeyType& name) const
	{
		return _val[name];
	}

private:
	ValueType _val;
};


} // namespace Dynamic

#ifdef min
#undef min
#endif
#ifdef max
#undef max
#endif
#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <iterator>
#include <limits>
#include <memory>
#include <stdexcept>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>


/**
 * Macros for compatibility with GCC 4.8
 */
#ifndef TSL_NO_CONTAINER_ERASE_CONST_ITERATOR
#if (defined(__GNUC__) && (__GNUC__ == 4) && (__GNUC_MINOR__ < 9))
#define TSL_NO_CONTAINER_ERASE_CONST_ITERATOR
#endif
#endif

#ifndef TSL_NO_CONTAINER_EMPLACE_CONST_ITERATOR
#if (defined(__GNUC__) && (__GNUC__ == 4) && (__GNUC_MINOR__ < 9))
#define TSL_NO_CONTAINER_EMPLACE_CONST_ITERATOR
#endif
#endif


 /*
  * Only activate tsl_assert if TSL_DEBUG is defined.
  * This way we avoid the performance hit when NDEBUG is not defined with assert as tsl_assert is used a lot
  * (people usually compile with "-O3" and not "-O3 -DNDEBUG").
  */
#ifndef tsl_assert
#ifdef TSL_DEBUG
#define tsl_assert(expr) assert(expr)
#else
#define tsl_assert(expr) (static_cast<void>(0))
#endif
#endif


namespace tsl {

namespace detail_ordered_hash {

template<typename T>
struct make_void {
	using type = void;
};

template<typename T, typename = void>
struct has_is_transparent : std::false_type {
};

template<typename T>
struct has_is_transparent<T, typename make_void<typename T::is_transparent>::type> : std::true_type {
};


template<typename T, typename = void>
struct is_vector : std::false_type {
};

template<typename T>
struct is_vector<T, typename std::enable_if<
	std::is_same<T, std::vector<typename T::value_type, typename T::allocator_type>>::value
>::type> : std::true_type {
};


/**
 * Each bucket entry stores a 32-bits index which is the index in m_values corresponding to the bucket's value
 * and a 32 bits hash (truncated if the original was 64-bits) corresponding to the hash of the value.
 *
 * The 32-bit index limits the size of the map to 2^32 - 1 elements (-1 due to a reserved value used to mark a
 * bucket as empty).
 */
class bucket_entry {
public:
	using index_type = std::uint_least32_t;
	using truncated_hash_type = std::uint_least32_t;


	bucket_entry() noexcept : m_index(EMPTY_MARKER_INDEX), m_hash(0) {
	}

	bool empty() const noexcept {
		return m_index == EMPTY_MARKER_INDEX;
	}

	void clear() noexcept {
		m_index = EMPTY_MARKER_INDEX;
	}

	index_type index() const noexcept {
		tsl_assert(!empty());
		return m_index;
	}

	index_type& index_ref() noexcept {
		tsl_assert(!empty());
		return m_index;
	}

	void set_index(index_type index) noexcept {
		tsl_assert(index <= max_size());

		m_index = index;
	}

	truncated_hash_type truncated_hash() const noexcept {
		tsl_assert(!empty());
		return m_hash;
	}

	truncated_hash_type& truncated_hash_ref() noexcept {
		tsl_assert(!empty());
		return m_hash;
	}

	void set_hash(std::size_t hash) noexcept {
		m_hash = truncate_hash(hash);
	}



	static truncated_hash_type truncate_hash(std::size_t hash) noexcept {
		return truncated_hash_type(hash);
	}

	static std::size_t max_size() noexcept {
		return std::numeric_limits<index_type>::max() - NB_RESERVED_INDEXES;
	}

private:
	static const index_type EMPTY_MARKER_INDEX = std::numeric_limits<index_type>::max();
	static const std::size_t NB_RESERVED_INDEXES = 1;

	index_type m_index;
	truncated_hash_type m_hash;
};



/**
 * Internal common class used by ordered_map and ordered_set.
 *
 * ValueType is what will be stored by ordered_hash (usually std::pair<Key, T> for map and Key for set).
 *
 * KeySelect should be a FunctionObject which takes a ValueType in parameter and return a reference to the key.
 *
 * ValueSelect should be a FunctionObject which takes a ValueType in parameter and return a reference to the value.
 * ValueSelect should be void if there is no value (in set for example).
 *
 * ValueTypeContainer is the container which will be used to store ValueType values.
 * Usually a std::deque<ValueType, Allocator> or std::vector<ValueType, Allocator>.
 *
 *
 *
 * The orderd_hash structure is a hash table which preserves the order of insertion of the elements.
 * To do so, it stores the values in the ValueTypeContainer (m_values) using emplace_back at each
 * insertion of a new element. Another structure (m_buckets of type std::vector<bucket_entry>) will
 * serve as buckets array for the hash table part. Each bucket stores an index which corresponds to
 * the index in m_values where the bucket's value is and the (truncated) hash of this value. An index
 * is used instead of a pointer to the value to reduce the size of each bucket entry.
 *
 * To resolve collisions in the buckets array, the structures use robin hood linear probing with
 * backward shift deletion.
 */
template<class ValueType,
	class KeySelect,
	class ValueSelect,
	class Hash,
	class KeyEqual,
	class Allocator,
	class ValueTypeContainer>
class ordered_hash : private Hash, private KeyEqual {
private:
	template<typename U>
	using has_mapped_type = typename std::integral_constant<bool, !std::is_same<U, void>::value>;

	static_assert(std::is_same<typename ValueTypeContainer::value_type, ValueType>::value,
		"ValueTypeContainer::value_type != ValueType.");
	static_assert(std::is_same<typename ValueTypeContainer::allocator_type, Allocator>::value,
		"ValueTypeContainer::allocator_type != Allocator.");


public:
	template<bool IsConst>
	class ordered_iterator;

	using key_type = typename KeySelect::key_type;
	using value_type = ValueType;
	using size_type = std::size_t;
	using difference_type = std::ptrdiff_t;
	using hasher = Hash;
	using key_equal = KeyEqual;
	using allocator_type = Allocator;
	using reference = value_type&;
	using const_reference = const value_type&;
	using pointer = value_type*;
	using const_pointer = const value_type*;
	using iterator = ordered_iterator<false>;
	using const_iterator = ordered_iterator<true>;
	using reverse_iterator = std::reverse_iterator<iterator>;
	using const_reverse_iterator = std::reverse_iterator<const_iterator>;

	using values_container_type = ValueTypeContainer;

public:
	template<bool IsConst>
	class ordered_iterator {
		friend class ordered_hash;

	private:
		using iterator = typename std::conditional<IsConst,
			typename values_container_type::const_iterator,
			typename values_container_type::iterator>::type;


		ordered_iterator(iterator it) noexcept : m_iterator(it) {
		}

	public:
		using iterator_category = std::random_access_iterator_tag;
		using value_type = const typename ordered_hash::value_type;
		using difference_type = typename iterator::difference_type;
		using reference = value_type&;
		using pointer = value_type*;


		ordered_iterator() noexcept {
		}

		ordered_iterator(const ordered_iterator<false>& other) noexcept : m_iterator(other.m_iterator) {
		}

		const typename ordered_hash::key_type& key() const {
			return KeySelect()(*m_iterator);
		}

		template<class U = ValueSelect, typename std::enable_if<has_mapped_type<U>::value&& IsConst>::type* = nullptr>
		const typename U::value_type& value() const {
			return U()(*m_iterator);
		}

		template<class U = ValueSelect, typename std::enable_if<has_mapped_type<U>::value && !IsConst>::type* = nullptr>
		typename U::value_type& value() {
			return U()(*m_iterator);
		}

		reference operator[](difference_type n) const { return m_iterator[n]; }

	private:
		iterator m_iterator;
	};


private:
	using buckets_container_allocator = typename
		std::allocator_traits<allocator_type>::template rebind_alloc<bucket_entry>;

	using buckets_container_type = std::vector<bucket_entry, buckets_container_allocator>;


	using truncated_hash_type = typename bucket_entry::truncated_hash_type;
	using index_type = typename bucket_entry::index_type;

public:
	ordered_hash(size_type bucket_count,
		const Hash& hash,
		const KeyEqual& equal,
		const Allocator& alloc,
		float max_load_factor) : Hash(hash), KeyEqual(equal), m_buckets(alloc),
		m_values(alloc), m_grow_on_next_insert(false)
	{
		bucket_count = round_up_to_power_of_two(bucket_count);
		if (bucket_count > max_bucket_count()) {
			throw std::length_error("The map exceeds its maxmimum size.");
		}
		tsl_assert(bucket_count > 0);

		m_buckets.resize(bucket_count);
		m_mask = bucket_count - 1;

		this->max_load_factor(max_load_factor);
	}

	allocator_type get_allocator() const {
		return m_values.get_allocator();
	}




	/*
	 * Capacity
	 */
	bool empty() const noexcept {
		return m_values.empty();
	}

	size_type size() const noexcept {
		return m_values.size();
	}

	size_type max_size() const noexcept {
		return std::min(bucket_entry::max_size(), m_values.max_size());
	}


	/*
	 * Modifiers
	 */
	void clear() noexcept {
		for (auto& bucket : m_buckets) {
			bucket.clear();
		}

		m_values.clear();
		m_grow_on_next_insert = false;
	}

	template<typename P>
	std::pair<iterator, bool> insert(P&& value) {
		return insert_impl(KeySelect()(value), std::forward<P>(value));
	}

	template<typename P>
	iterator insert(const_iterator hint, P&& value) {
		if (hint != cend() && compare_keys(KeySelect()(*hint), KeySelect()(value))) {
			return mutable_iterator(hint);
		}

		return insert(std::forward<P>(value)).first;
	}

	template<class InputIt>
	void insert(InputIt first, InputIt last) {
		if (std::is_base_of<std::forward_iterator_tag,
			typename std::iterator_traits<InputIt>::iterator_category>::value)
		{
			const auto nb_elements_insert = std::distance(first, last);
			const size_type nb_free_buckets = m_load_threshold - size();
			tsl_assert(m_load_threshold >= size());

			if (nb_elements_insert > 0 && nb_free_buckets < size_type(nb_elements_insert)) {
				reserve(size() + size_type(nb_elements_insert));
			}
		}

		for (; first != last; ++first) {
			insert(*first);
		}
	}



	template<class K, class M>
	std::pair<iterator, bool> insert_or_assign(K&& key, M&& value) {
		auto it = try_emplace(std::forward<K>(key), std::forward<M>(value));
		if (!it.second) {
			it.first.value() = std::forward<M>(value);
		}

		return it;
	}

	template<class K, class M>
	iterator insert_or_assign(const_iterator hint, K&& key, M&& obj) {
		if (hint != cend() && compare_keys(KeySelect()(*hint), key)) {
			auto it = mutable_iterator(hint);
			it.value() = std::forward<M>(obj);

			return it;
		}

		return insert_or_assign(std::forward<K>(key), std::forward<M>(obj)).first;
	}



	template<class... Args>
	std::pair<iterator, bool> emplace(Args&&... args) {
		return insert(value_type(std::forward<Args>(args)...));
	}

	template<class... Args>
	iterator emplace_hint(const_iterator hint, Args&&... args) {
		return insert(hint, value_type(std::forward<Args>(args)...));
	}



	template<class K, class... Args>
	std::pair<iterator, bool> try_emplace(K&& key, Args&&... value_args) {
		return insert_impl(key, std::piecewise_construct,
			std::forward_as_tuple(std::forward<K>(key)),
			std::forward_as_tuple(std::forward<Args>(value_args)...));
	}

	template<class K, class... Args>
	iterator try_emplace(const_iterator hint, K&& key, Args&&... args) {
		if (hint != cend() && compare_keys(KeySelect()(*hint), key)) {
			return mutable_iterator(hint);
		}

		return try_emplace(std::forward<K>(key), std::forward<Args>(args)...).first;
	}



	/**
	 * Here to avoid `template<class K> size_type erase(const K& key)` being used when
	 * we use a iterator instead of a const_iterator.
	 */
	iterator erase(iterator pos) {
		return erase(const_iterator(pos));
	}

	iterator erase(const_iterator pos) {
		tsl_assert(pos != cend());

		const std::size_t index_erase = iterator_to_index(pos);

		auto it_bucket = find_key(pos.key(), hash_key(pos.key()));
		tsl_assert(it_bucket != m_buckets.end());

		erase_value_from_bucket(it_bucket);

		/*
		 * One element was removed from m_values, due to the left shift the next element
		 * is now at the position of the previous element (or end if none).
		 */
		return begin() + index_erase;
	}

	iterator erase(const_iterator first, const_iterator last) {
		if (first == last) {
			return mutable_iterator(first);
		}

		tsl_assert(std::distance(first, last) > 0);
		const std::size_t start_index = iterator_to_index(first);
		const std::size_t nb_values = std::size_t(std::distance(first, last));
		const std::size_t end_index = start_index + nb_values;

		// Delete all values
#ifdef TSL_NO_CONTAINER_ERASE_CONST_ITERATOR
		auto next_it = m_values.erase(mutable_iterator(first).m_iterator, mutable_iterator(last).m_iterator);
#else
		auto next_it = m_values.erase(first.m_iterator, last.m_iterator);
#endif

		/*
		 * Mark the buckets corresponding to the values as empty and do a backward shift.
		 *
		 * Also, the erase operation on m_values has shifted all the values on the right of last.m_iterator.
		 * Adapt the indexes for these values.
		 */
		std::size_t ibucket = 0;
		while (ibucket < m_buckets.size()) {
			if (m_buckets[ibucket].empty()) {
				ibucket++;
			}
			else if (m_buckets[ibucket].index() >= start_index && m_buckets[ibucket].index() < end_index) {
				m_buckets[ibucket].clear();
				backward_shift(ibucket);
				// Don't increment ibucket, backward_shift may have replaced current bucket.
			}
			else if (m_buckets[ibucket].index() >= end_index) {
				m_buckets[ibucket].set_index(index_type(m_buckets[ibucket].index() - nb_values));
				ibucket++;
			}
			else {
				ibucket++;
			}
		}

		return iterator(next_it);
	}


	template<class K>
	size_type erase(const K& key) {
		return erase(key, hash_key(key));
	}

	template<class K>
	size_type erase(const K& key, std::size_t hash) {
		return erase_impl(key, hash);
	}

	void swap(ordered_hash& other) noexcept {
		using std::swap;

		swap(static_cast<Hash&>(*this), static_cast<Hash&>(other));
		swap(static_cast<KeyEqual&>(*this), static_cast<KeyEqual&>(other));
		swap(m_buckets, other.m_buckets);
		swap(m_mask, other.m_mask);
		swap(m_values, other.m_values);
		swap(m_grow_on_next_insert, other.m_grow_on_next_insert);
		swap(m_max_load_factor, other.m_max_load_factor);
		swap(m_load_threshold, other.m_load_threshold);
	}





	template<class K, class U = ValueSelect, typename std::enable_if<has_mapped_type<U>::value>::type* = nullptr>
	typename U::value_type& operator[](K&& key) {
		return try_emplace(std::forward<K>(key)).first.value();
	}


	template<class K>
	size_type count(const K& key) const {
		return count(key, hash_key(key));
	}

	template<class K>
	size_type count(const K& key, std::size_t hash) const {
		if (find(key, hash) == cend()) {
			return 0;
		}
		else {
			return 1;
		}
	}

	template<class K>
	iterator find(const K& key) {
		return find(key, hash_key(key));
	}

	template<class K>
	iterator find(const K& key, std::size_t hash) {
		auto it_bucket = find_key(key, hash);
		return (it_bucket != m_buckets.end()) ? iterator(m_values.begin() + it_bucket->index()) : end();
	}

	template<class K>
	const_iterator find(const K& key) const {
		return find(key, hash_key(key));
	}

	template<class K>
	const_iterator find(const K& key, std::size_t hash) const {
		auto it_bucket = find_key(key, hash);
		return (it_bucket != m_buckets.cend()) ? const_iterator(m_values.begin() + it_bucket->index()) : end();
	}



	/*
	 * Bucket interface
	 */
	size_type bucket_count() const {
		return m_buckets.size();
	}

	size_type max_bucket_count() const {
		return m_buckets.max_size();
	}

	/*
	 *  Hash policy
	 */
	float load_factor() const {
		return float(size()) / float(bucket_count());
	}

	float max_load_factor() const {
		return m_max_load_factor;
	}

	void max_load_factor(float ml) {
		m_max_load_factor = std::max(0.1f, std::min(ml, 0.95f));
		m_load_threshold = size_type(float(bucket_count()) * m_max_load_factor);
	}

	void rehash(size_type count) {
		count = std::max(count, size_type(std::ceil(float(size()) / max_load_factor())));
		rehash_impl(count);
	}

	void reserve(size_type count) {
		reserve_space_for_values(count);

		count = size_type(std::ceil(float(count) / max_load_factor()));
		rehash(count);
	}


	/*
	 * Observers
	 */
	hasher hash_function() const {
		return static_cast<const Hash&>(*this);
	}

	key_equal key_eq() const {
		return static_cast<const KeyEqual&>(*this);
	}


	/*
	 * Other
	 */
	iterator mutable_iterator(const_iterator pos) {
		return iterator(m_values.begin() + iterator_to_index(pos));
	}

	iterator nth(size_type index) {
		return iterator(m_values.begin() + index);
	}

	const_iterator nth(size_type index) const {
		return const_iterator(m_values.cbegin() + index);
	}

	const_reference front() const {
		return m_values.front();
	}

	const_reference back() const {
		return m_values.back();
	}

	const values_container_type& values_container() const noexcept {
		return m_values;
	}

	template<class U = values_container_type, typename std::enable_if<is_vector<U>::value>::type* = nullptr>
	const typename values_container_type::value_type* data() const noexcept {
		return m_values.data();
	}

	template<class U = values_container_type, typename std::enable_if<is_vector<U>::value>::type* = nullptr>
	size_type capacity() const noexcept {
		return m_values.capacity();
	}

	void shrink_to_fit() {
		m_values.shrink_to_fit();
	}

private:
	template<class K>
	std::size_t hash_key(const K& key) const {
		return Hash::operator()(key);
	}

	template<class K1, class K2>
	bool compare_keys(const K1& key1, const K2& key2) const {
		return KeyEqual::operator()(key1, key2);
	}

	template<class K>
	typename buckets_container_type::iterator find_key(const K& key, std::size_t hash) {
		auto it = static_cast<const ordered_hash*>(this)->find_key(key, hash);
		return m_buckets.begin() + std::distance(m_buckets.cbegin(), it);
	}

	/**
	 * Return bucket which has the key 'key' or m_buckets.end() if none.
	 *
	 * From the bucket_for_hash, search for the value until we either find an empty bucket
	 * or a bucket which has a value with a distance from its ideal bucket longer
	 * than the probe length for the value we are looking for.
	 */
	template<class K>
	typename buckets_container_type::const_iterator find_key(const K& key, std::size_t hash) const {
		for (std::size_t ibucket = bucket_for_hash(hash), dist_from_ideal_bucket = 0; ;
			ibucket = next_bucket(ibucket), dist_from_ideal_bucket++)
		{
			if (m_buckets[ibucket].empty()) {
				return m_buckets.end();
			}
			else if (m_buckets[ibucket].truncated_hash() == bucket_entry::truncate_hash(hash) &&
				compare_keys(key, KeySelect()(m_values[m_buckets[ibucket].index()])))
			{
				return m_buckets.begin() + ibucket;
			}
			else if (dist_from_ideal_bucket > distance_from_ideal_bucket(ibucket)) {
				return m_buckets.end();
			}
		}
	}

	void rehash_impl(size_type bucket_count) {
		bucket_count = round_up_to_power_of_two(bucket_count);
		tsl_assert(bucket_count > 0);

		if (bucket_count == this->bucket_count()) {
			return;
		}

		if (bucket_count > max_bucket_count()) {
			throw std::length_error("The map exceeds its maxmimum size.");
		}


		buckets_container_type old_buckets(bucket_count);
		m_buckets.swap(old_buckets);
		// Everything should be noexcept from here.

		m_mask = bucket_count - 1;
		this->max_load_factor(m_max_load_factor);
		m_grow_on_next_insert = false;



		for (const bucket_entry& old_bucket : old_buckets) {
			if (old_bucket.empty()) {
				continue;
			}

			truncated_hash_type insert_hash = old_bucket.truncated_hash();
			index_type insert_index = old_bucket.index();

			for (std::size_t ibucket = bucket_for_hash(insert_hash), dist_from_ideal_bucket = 0; ;
				ibucket = next_bucket(ibucket), dist_from_ideal_bucket++)
			{
				if (m_buckets[ibucket].empty()) {
					m_buckets[ibucket].set_index(insert_index);
					m_buckets[ibucket].set_hash(insert_hash);
					break;
				}

				const std::size_t distance = distance_from_ideal_bucket(ibucket);
				if (dist_from_ideal_bucket > distance) {
					std::swap(insert_index, m_buckets[ibucket].index_ref());
					std::swap(insert_hash, m_buckets[ibucket].truncated_hash_ref());
					dist_from_ideal_bucket = distance;
				}
			}
		}
	}

	template<class T = values_container_type, typename std::enable_if<is_vector<T>::value>::type* = nullptr>
	void reserve_space_for_values(size_type count) {
		m_values.reserve(count);
	}

	template<class T = values_container_type, typename std::enable_if<!is_vector<T>::value>::type* = nullptr>
	void reserve_space_for_values(size_type /*count*/) {
	}

	/**
	 * Swap the empty bucket with the values on its right until we cross another empty bucket
	 * or if the other bucket has a distance_from_ideal_bucket == 0.
	 */
	void backward_shift(std::size_t empty_ibucket) noexcept {
		tsl_assert(m_buckets[empty_ibucket].empty());

		std::size_t previous_ibucket = empty_ibucket;
		for (std::size_t current_ibucket = next_bucket(previous_ibucket);
			!m_buckets[current_ibucket].empty() && distance_from_ideal_bucket(current_ibucket) > 0;
			previous_ibucket = current_ibucket, current_ibucket = next_bucket(current_ibucket))
		{
			std::swap(m_buckets[current_ibucket], m_buckets[previous_ibucket]);
		}
	}

	void erase_value_from_bucket(typename buckets_container_type::iterator it_bucket) {
		tsl_assert(it_bucket != m_buckets.end() && !it_bucket->empty());

		m_values.erase(m_values.begin() + it_bucket->index());

		/*
		 * m_values.erase shifted all the values on the right of the erased value,
		 * shift the indexes by 1 in the buckets array for these values.
		 */
		if (it_bucket->index() != m_values.size()) {
			shift_indexes_in_buckets(it_bucket->index(), short(1));
		}

		// Mark the bucket as empty and do a backward shift of the values on the right
		it_bucket->clear();
		backward_shift(std::size_t(std::distance(m_buckets.begin(), it_bucket)));
	}

	/**
	 * Go through each value from [from_ivalue, m_values.size()) in m_values and for each
	 * bucket corresponding to the value, shift the indexes to the left by delta.
	 */
	void shift_indexes_in_buckets(index_type from_ivalue, short delta) noexcept {
		static_assert(std::is_unsigned<index_type>::value && sizeof(index_type) >= sizeof(short),
			"index_type should be unsigned and sizeof(index_type) >= sizeof(short)");

		for (std::size_t ivalue = from_ivalue; ivalue < m_values.size(); ivalue++) {
			std::size_t ibucket = bucket_for_hash(hash_key(KeySelect()(m_values[ivalue])));

			// Modulo arithmetic, we should be alright for index_type(ivalue + delta). TODO further checks
			while (m_buckets[ibucket].index() != index_type(ivalue + delta)) {
				ibucket = next_bucket(ibucket);
			}

			m_buckets[ibucket].set_index(index_type(m_buckets[ibucket].index() - delta));
		}
	}

	template<class K>
	size_type erase_impl(const K& key, std::size_t hash) {
		auto it_bucket = find_key(key, hash);
		if (it_bucket != m_buckets.end()) {
			erase_value_from_bucket(it_bucket);

			return 1;
		}
		else {
			return 0;
		}
	}

	template<class K, class... Args>
	std::pair<iterator, bool> insert_impl(const K& key, Args&&... value_type_args) {
		return insert_at_position_impl(m_values.cend(), key, std::forward<Args>(value_type_args)...);
	}

	/**
	 * Insert the element before insert_position.
	 */
	template<class K, class... Args>
	std::pair<iterator, bool> insert_at_position_impl(typename values_container_type::const_iterator insert_position,
		const K& key, Args&&... value_type_args)
	{
		const std::size_t hash = hash_key(key);

		std::size_t ibucket = bucket_for_hash(hash);
		std::size_t dist_from_ideal_bucket = 0;

		while (!m_buckets[ibucket].empty() && dist_from_ideal_bucket <= distance_from_ideal_bucket(ibucket)) {
			if (m_buckets[ibucket].truncated_hash() == bucket_entry::truncate_hash(hash) &&
				compare_keys(key, KeySelect()(m_values[m_buckets[ibucket].index()])))
			{
				return std::make_pair(begin() + m_buckets[ibucket].index(), false);
			}

			ibucket = next_bucket(ibucket);
			dist_from_ideal_bucket++;
		}

		if (size() >= max_size()) {
			throw std::length_error("We reached the maximum size for the hash table.");
		}


		if (grow_on_high_load()) {
			ibucket = bucket_for_hash(hash);
			dist_from_ideal_bucket = 0;
		}


		const index_type index_insert_position = index_type(std::distance(m_values.cbegin(), insert_position));

#ifdef TSL_NO_CONTAINER_EMPLACE_CONST_ITERATOR
		m_values.emplace(m_values.begin() + std::distance(m_values.cbegin(), insert_position), std::forward<Args>(value_type_args)...);
#else
		m_values.emplace(insert_position, std::forward<Args>(value_type_args)...);
#endif

		insert_index(ibucket, dist_from_ideal_bucket,
			index_insert_position, bucket_entry::truncate_hash(hash));

		/*
		 * The insertion didn't happend at the end of the m_values container,
		 * we need to shift the indexes in m_buckets.
		 */
		if (index_insert_position != m_values.size() - 1) {
			shift_indexes_in_buckets(index_insert_position + 1, short(-1));
		}

		return std::make_pair(iterator(m_values.begin() + index_insert_position), true);
	}

	void insert_index(std::size_t ibucket, std::size_t dist_from_ideal_bucket,
		index_type index_insert, truncated_hash_type hash_insert) noexcept
	{
		while (!m_buckets[ibucket].empty()) {
			const std::size_t distance = distance_from_ideal_bucket(ibucket);
			if (dist_from_ideal_bucket > distance) {
				std::swap(index_insert, m_buckets[ibucket].index_ref());
				std::swap(hash_insert, m_buckets[ibucket].truncated_hash_ref());

				dist_from_ideal_bucket = distance;
			}


			ibucket = next_bucket(ibucket);
			dist_from_ideal_bucket++;


			if (dist_from_ideal_bucket > REHASH_ON_HIGH_NB_PROBES__NPROBES && !m_grow_on_next_insert &&
				load_factor() >= REHASH_ON_HIGH_NB_PROBES__MIN_LOAD_FACTOR)
			{
				// We don't want to grow the map now as we need this method to be noexcept.
				// Do it on next insert.
				m_grow_on_next_insert = true;
			}
		}


		m_buckets[ibucket].set_index(index_insert);
		m_buckets[ibucket].set_hash(hash_insert);
	}

	std::size_t distance_from_ideal_bucket(std::size_t ibucket) const noexcept {
		const std::size_t ideal_bucket = bucket_for_hash(m_buckets[ibucket].truncated_hash());

		if (ibucket >= ideal_bucket) {
			return ibucket - ideal_bucket;
		}
		// If the bucket is smaller than the ideal bucket for the value, there was a wrapping at the end of the
		// bucket array due to the modulo.
		else {
			return (bucket_count() + ibucket) - ideal_bucket;
		}
	}

	std::size_t next_bucket(std::size_t index) const noexcept {
		tsl_assert(index < m_buckets.size());

		index++;
		return (index < m_buckets.size()) ? index : 0;
	}

	std::size_t bucket_for_hash(std::size_t hash) const noexcept {
		return hash & m_mask;
	}

	std::size_t iterator_to_index(const_iterator it) const noexcept {
		const auto dist = std::distance(cbegin(), it);
		tsl_assert(dist >= 0);

		return std::size_t(dist);
	}

	/**
	 * Return true if the map has been rehashed.
	 */
	bool grow_on_high_load() {
		if (m_grow_on_next_insert || size() >= m_load_threshold) {
			rehash_impl(bucket_count() * 2);
			m_grow_on_next_insert = false;

			return true;
		}
		else {
			return false;
		}
	}

	static std::size_t round_up_to_power_of_two(std::size_t value) {
		if (is_power_of_two(value)) {
			return value;
		}

		if (value == 0) {
			return 1;
		}

		--value;
		for (std::size_t i = 1; i < sizeof(std::size_t) * CHAR_BIT; i *= 2) {
			value |= value >> i;
		}

		return value + 1;
	}

	static constexpr bool is_power_of_two(std::size_t value) {
		return value != 0 && (value & (value - 1)) == 0;
	}


public:
	static const size_type DEFAULT_INIT_BUCKETS_SIZE = 16;
	static constexpr float DEFAULT_MAX_LOAD_FACTOR = 0.75f;

private:
	static const size_type REHASH_ON_HIGH_NB_PROBES__NPROBES = 128;
	static constexpr float REHASH_ON_HIGH_NB_PROBES__MIN_LOAD_FACTOR = 0.15f;

private:
	buckets_container_type m_buckets;
	size_type m_mask;

	values_container_type m_values;

	bool m_grow_on_next_insert;
	float m_max_load_factor;
	size_type m_load_threshold;
};


} // end namespace detail_ordered_hash

} // end namespace tsl

#include <cstddef>
#include <deque>
#include <functional>
#include <initializer_list>
#include <memory>
#include <type_traits>
#include <utility>
#include <vector>
//#include "ordered_hash.h"


namespace tsl {


/**
 * Implementation of an hash set using open adressing with robin hood with backshift delete to resolve collisions.
 *
 * The particularity of this hash set is that it remembers the order in which the elements were added and
 * provide a way to access the structure which stores these values through the 'values_container()' method.
 * The used container is defined by ValueTypeContainer, by default a std::deque is used (grows faster) but
 * a std::vector may be used. In this case the set provides a 'data()' method which give a direct access
 * to the memory used to store the values (which can be usefull to communicate with C API's).
 *
 * The Key must be copy constructible and/or move constructible. To use `unordered_erase` it also must be swappable.
 *
 * The behaviour of the hash set is undefinded if the destructor of Key throws an exception.
 *
 * Iterators invalidation:
 *  - clear, operator=, reserve, rehash: always invalidate the iterators (also invalidate end()).
 *  - insert, emplace, emplace_hint, operator[]: when a std::vector is used as ValueTypeContainer
 *                                               and if size() < capacity(), only end().
 *                                               Otherwise all the iterators are invalidated if an insert occurs.
 *  - erase, unordered_erase: when a std::vector is used as ValueTypeContainer invalidate the iterator of
 *                            the erased element and all the ones after the erased element (including end()).
 *                            Otherwise all the iterators are invalidated if an erase occurs.
 */
template<class Key,
	class Hash = std::hash<Key>,
	class KeyEqual = std::equal_to<Key>,
	class Allocator = std::allocator<Key>,
	class ValueTypeContainer = std::deque<Key, Allocator>>
	class ordered_set {
	private:
		template<typename U>
		using has_is_transparent = tsl::detail_ordered_hash::has_is_transparent<U>;

		class KeySelect {
		public:
			using key_type = Key;

			const key_type& operator()(const Key& key) const noexcept {
				return key;
			}

			key_type& operator()(Key& key) noexcept {
				return key;
			}
		};

		using ht = detail_ordered_hash::ordered_hash<Key, KeySelect, void,
			Hash, KeyEqual, Allocator, ValueTypeContainer>;

	public:
		using key_type = typename ht::key_type;
		using value_type = typename ht::value_type;
		using size_type = typename ht::size_type;
		using difference_type = typename ht::difference_type;
		using hasher = typename ht::hasher;
		using key_equal = typename ht::key_equal;
		using allocator_type = typename ht::allocator_type;
		using reference = typename ht::reference;
		using const_reference = typename ht::const_reference;
		using pointer = typename ht::pointer;
		using const_pointer = typename ht::const_pointer;
		using iterator = typename ht::iterator;
		using const_iterator = typename ht::const_iterator;
		using reverse_iterator = typename ht::reverse_iterator;
		using const_reverse_iterator = typename ht::const_reverse_iterator;

		using values_container_type = typename ht::values_container_type;


		/*
		 * Constructors
		 */
		ordered_set() : ordered_set(ht::DEFAULT_INIT_BUCKETS_SIZE) {
		}

		explicit ordered_set(size_type bucket_count,
			const Hash& hash = Hash(),
			const KeyEqual& equal = KeyEqual(),
			const Allocator& alloc = Allocator()) :
			m_ht(bucket_count, hash, equal, alloc, ht::DEFAULT_MAX_LOAD_FACTOR)
		{
		}

		ordered_set(size_type bucket_count,
			const Allocator& alloc) : ordered_set(bucket_count, Hash(), KeyEqual(), alloc)
		{
		}

		ordered_set(size_type bucket_count,
			const Hash& hash,
			const Allocator& alloc) : ordered_set(bucket_count, hash, KeyEqual(), alloc)
		{
		}

		explicit ordered_set(const Allocator& alloc) : ordered_set(ht::DEFAULT_INIT_BUCKETS_SIZE, alloc) {
		}

		template<class InputIt>
		ordered_set(InputIt first, InputIt last,
			size_type bucket_count = ht::DEFAULT_INIT_BUCKETS_SIZE,
			const Hash& hash = Hash(),
			const KeyEqual& equal = KeyEqual(),
			const Allocator& alloc = Allocator()) : ordered_set(bucket_count, hash, equal, alloc)
		{
			insert(first, last);
		}

		template<class InputIt>
		ordered_set(InputIt first, InputIt last,
			size_type bucket_count,
			const Allocator& alloc) : ordered_set(first, last, bucket_count, Hash(), KeyEqual(), alloc)
		{
		}

		template<class InputIt>
		ordered_set(InputIt first, InputIt last,
			size_type bucket_count,
			const Hash& hash,
			const Allocator& alloc) : ordered_set(first, last, bucket_count, hash, KeyEqual(), alloc)
		{
		}

		ordered_set(std::initializer_list<value_type> init,
			size_type bucket_count = ht::DEFAULT_INIT_BUCKETS_SIZE,
			const Hash& hash = Hash(),
			const KeyEqual& equal = KeyEqual(),
			const Allocator& alloc = Allocator()) :
			ordered_set(init.begin(), init.end(), bucket_count, hash, equal, alloc)
		{
		}

		ordered_set(std::initializer_list<value_type> init,
			size_type bucket_count,
			const Allocator& alloc) :
			ordered_set(init.begin(), init.end(), bucket_count, Hash(), KeyEqual(), alloc)
		{
		}

		ordered_set(std::initializer_list<value_type> init,
			size_type bucket_count,
			const Hash& hash,
			const Allocator& alloc) :
			ordered_set(init.begin(), init.end(), bucket_count, hash, KeyEqual(), alloc)
		{
		}


		ordered_set& operator=(std::initializer_list<value_type> ilist) {
			m_ht.clear();

			m_ht.reserve(ilist.size());
			m_ht.insert(ilist.begin(), ilist.end());

			return *this;
		}

		allocator_type get_allocator() const { return m_ht.get_allocator(); }


		void swap(ordered_set& other) noexcept { other.m_ht.swap(m_ht); }

		/*
		 * Lookup
		 */
		size_type count(const Key& key) const { return m_ht.count(key); }

		/**
		 * Use the hash value 'precalculated_hash' instead of hashing the key. The hash value should be the same
		 * as hash_function()(key). Usefull to speed-up the lookup if you already have the hash.
		 */
		size_type count(const Key& key, std::size_t precalculated_hash) const {
			return m_ht.count(key, precalculated_hash);
		}

		/**
		 * This overload only participates in the overload resolution if the typedef KeyEqual::is_transparent exists.
		 * If so, K must be hashable and comparable to Key.
		 */
		template<class K, class KE = KeyEqual, typename std::enable_if<has_is_transparent<KE>::value>::type* = nullptr>
		size_type count(const K& key) const { return m_ht.count(key); }

		/**
		 * @copydoc count(const K& key) const
		 *
		 * Use the hash value 'precalculated_hash' instead of hashing the key. The hash value should be the same
		 * as hash_function()(key). Usefull to speed-up the lookup if you already have the hash.
		 */
		template<class K, class KE = KeyEqual, typename std::enable_if<has_is_transparent<KE>::value>::type* = nullptr>
		size_type count(const K& key, std::size_t precalculated_hash) const {
			return m_ht.count(key, precalculated_hash);
		}




		iterator find(const Key& key) { return m_ht.find(key); }

		/**
		 * Use the hash value 'precalculated_hash' instead of hashing the key. The hash value should be the same
		 * as hash_function()(key). Usefull to speed-up the lookup if you already have the hash.
		 */
		iterator find(const Key& key, std::size_t precalculated_hash) { return m_ht.find(key, precalculated_hash); }

		const_iterator find(const Key& key) const { return m_ht.find(key); }

		/**
		 * @copydoc find(const Key& key, std::size_t precalculated_hash)
		 */
		const_iterator find(const Key& key, std::size_t precalculated_hash) const {
			return m_ht.find(key, precalculated_hash);
		}

		/**
		 * This overload only participates in the overload resolution if the typedef KeyEqual::is_transparent exists.
		 * If so, K must be hashable and comparable to Key.
		 */
		template<class K, class KE = KeyEqual, typename std::enable_if<has_is_transparent<KE>::value>::type* = nullptr>
		iterator find(const K& key) { return m_ht.find(key); }

		/**
		 * @copydoc find(const K& key)
		 *
		 * Use the hash value 'precalculated_hash' instead of hashing the key. The hash value should be the same
		 * as hash_function()(key). Usefull to speed-up the lookup if you already have the hash.
		 */
		template<class K, class KE = KeyEqual, typename std::enable_if<has_is_transparent<KE>::value>::type* = nullptr>
		iterator find(const K& key, std::size_t precalculated_hash) { return m_ht.find(key, precalculated_hash); }

		/**
		 * @copydoc find(const K& key)
		 */
		template<class K, class KE = KeyEqual, typename std::enable_if<has_is_transparent<KE>::value>::type* = nullptr>
		const_iterator find(const K& key) const { return m_ht.find(key); }

		/**
		 * @copydoc find(const K& key)
		 *
		 * Use the hash value 'precalculated_hash' instead of hashing the key. The hash value should be the same
		 * as hash_function()(key). Usefull to speed-up the lookup if you already have the hash.
		 */
		template<class K, class KE = KeyEqual, typename std::enable_if<has_is_transparent<KE>::value>::type* = nullptr>
		const_iterator find(const K& key, std::size_t precalculated_hash) const {
			return m_ht.find(key, precalculated_hash);
		}



		std::pair<iterator, iterator> equal_range(const Key& key) { return m_ht.equal_range(key); }

		/**
		 * Use the hash value 'precalculated_hash' instead of hashing the key. The hash value should be the same
		 * as hash_function()(key). Usefull to speed-up the lookup if you already have the hash.
		 */
		std::pair<iterator, iterator> equal_range(const Key& key, std::size_t precalculated_hash) {
			return m_ht.equal_range(key, precalculated_hash);
		}

		std::pair<const_iterator, const_iterator> equal_range(const Key& key) const { return m_ht.equal_range(key); }

		/**
		 * @copydoc equal_range(const Key& key, std::size_t precalculated_hash)
		 */
		std::pair<const_iterator, const_iterator> equal_range(const Key& key, std::size_t precalculated_hash) const {
			return m_ht.equal_range(key, precalculated_hash);
		}

		/**
		 * This overload only participates in the overload resolution if the typedef KeyEqual::is_transparent exists.
		 * If so, K must be hashable and comparable to Key.
		 */
		template<class K, class KE = KeyEqual, typename std::enable_if<has_is_transparent<KE>::value>::type* = nullptr>
		std::pair<iterator, iterator> equal_range(const K& key) { return m_ht.equal_range(key); }

		/**
		 * @copydoc equal_range(const K& key)
		 *
		 * Use the hash value 'precalculated_hash' instead of hashing the key. The hash value should be the same
		 * as hash_function()(key). Usefull to speed-up the lookup if you already have the hash.
		 */
		template<class K, class KE = KeyEqual, typename std::enable_if<has_is_transparent<KE>::value>::type* = nullptr>
		std::pair<iterator, iterator> equal_range(const K& key, std::size_t precalculated_hash) {
			return m_ht.equal_range(key, precalculated_hash);
		}

		/**
		 * @copydoc equal_range(const K& key)
		 */
		template<class K, class KE = KeyEqual, typename std::enable_if<has_is_transparent<KE>::value>::type* = nullptr>
		std::pair<const_iterator, const_iterator> equal_range(const K& key) const { return m_ht.equal_range(key); }

		/**
		 * @copydoc equal_range(const K& key, std::size_t precalculated_hash)
		 */
		template<class K, class KE = KeyEqual, typename std::enable_if<has_is_transparent<KE>::value>::type* = nullptr>
		std::pair<const_iterator, const_iterator> equal_range(const K& key, std::size_t precalculated_hash) const {
			return m_ht.equal_range(key, precalculated_hash);
		}


		/*
		 * Bucket interface
		 */
		size_type bucket_count() const { return m_ht.bucket_count(); }
		size_type max_bucket_count() const { return m_ht.max_bucket_count(); }


		/*
		 *  Hash policy
		 */
		float load_factor() const { return m_ht.load_factor(); }
		float max_load_factor() const { return m_ht.max_load_factor(); }
		void max_load_factor(float ml) { m_ht.max_load_factor(ml); }

		void rehash(size_type count) { m_ht.rehash(count); }
		void reserve(size_type count) { m_ht.reserve(count); }


		/*
		 * Observers
		 */
		hasher hash_function() const { return m_ht.hash_function(); }
		key_equal key_eq() const { return m_ht.key_eq(); }


		/*
		 * Other
		 */

		 /**
		  * Convert a const_iterator to an iterator.
		  */
		iterator mutable_iterator(const_iterator pos) {
			return m_ht.mutable_iterator(pos);
		}

		/**
		 * Requires index <= size().
		 *
		 * Return an iterator to the element at index. Return end() if index == size().
		 */
		iterator nth(size_type index) { return m_ht.nth(index); }

		/**
		 * @copydoc nth(size_type index)
		 */
		const_iterator nth(size_type index) const { return m_ht.nth(index); }


		/**
		 * Return const_reference to the first element. Requires the container to not be empty.
		 */
		const_reference front() const { return m_ht.front(); }

		/**
		 * Return const_reference to the last element. Requires the container to not be empty.
		 */
		const_reference back() const { return m_ht.back(); }


		/**
		 * Only available if ValueTypeContainer is a std::vector. Same as calling 'values_container().data()'.
		 */
		template<class U = values_container_type, typename std::enable_if<tsl::detail_ordered_hash::is_vector<U>::value>::type* = nullptr>
		const typename values_container_type::value_type* data() const noexcept { return m_ht.data(); }

		/**
		 * Return the container in which the values are stored. The values are in the same order as the insertion order
		 * and are contiguous in the structure, no holes (size() == values_container().size()).
		 */
		const values_container_type& values_container() const noexcept { return m_ht.values_container(); }

		template<class U = values_container_type, typename std::enable_if<tsl::detail_ordered_hash::is_vector<U>::value>::type* = nullptr>
		size_type capacity() const noexcept { return m_ht.capacity(); }

		void shrink_to_fit() { m_ht.shrink_to_fit(); }



		/**
		 * Insert the value before pos shifting all the elements on the right of pos (including pos) one position
		 * to the right.
		 *
		 * Amortized linear time-complexity in the distance between pos and end().
		 */
		std::pair<iterator, bool> insert_at_position(const_iterator pos, const value_type& value) {
			return m_ht.insert_at_position(pos, value);
		}

		/**
		 * @copydoc insert_at_position(const_iterator pos, const value_type& value)
		 */
		std::pair<iterator, bool> insert_at_position(const_iterator pos, value_type&& value) {
			return m_ht.insert_at_position(pos, std::move(value));
		}

		/**
		 * @copydoc insert_at_position(const_iterator pos, const value_type& value)
		 *
		 * Same as insert_at_position(pos, value_type(std::forward<Args>(args)...), mainly
		 * here for coherence.
		 */
		template<class... Args>
		std::pair<iterator, bool> emplace_at_position(const_iterator pos, Args&&... args) {
			return m_ht.emplace_at_position(pos, std::forward<Args>(args)...);
		}



		void pop_back() { m_ht.pop_back(); }

		/**
		 * Faster erase operation with an O(1) average complexity but it doesn't preserve the insertion order.
		 *
		 * If an erasure occurs, the last element of the map will take the place of the erased element.
		 */
		iterator unordered_erase(iterator pos) { return m_ht.unordered_erase(pos); }

		/**
		 * @copydoc unordered_erase(iterator pos)
		 */
		iterator unordered_erase(const_iterator pos) { return m_ht.unordered_erase(pos); }

		/**
		 * @copydoc unordered_erase(iterator pos)
		 */
		size_type unordered_erase(const key_type& key) { return m_ht.unordered_erase(key); }

		/**
		 * @copydoc unordered_erase(iterator pos)
		 *
		 * Use the hash value 'precalculated_hash' instead of hashing the key. The hash value should be the same
		 * as hash_function()(key). Usefull to speed-up the lookup if you already have the hash.
		 */
		size_type unordered_erase(const key_type& key, std::size_t precalculated_hash) {
			return m_ht.unordered_erase(key, precalculated_hash);
		}

		/**
		 * @copydoc unordered_erase(iterator pos)
		 *
		 * This overload only participates in the overload resolution if the typedef KeyEqual::is_transparent exists.
		 * If so, K must be hashable and comparable to Key.
		 */
		template<class K, class KE = KeyEqual, typename std::enable_if<has_is_transparent<KE>::value>::type* = nullptr>
		size_type unordered_erase(const K& key) { return m_ht.unordered_erase(key); }

		/**
		 * @copydoc unordered_erase(const K& key)
		 *
		 * Use the hash value 'precalculated_hash' instead of hashing the key. The hash value should be the same
		 * as hash_function()(key). Usefull to speed-up the lookup if you already have the hash.
		 */
		template<class K, class KE = KeyEqual, typename std::enable_if<has_is_transparent<KE>::value>::type* = nullptr>
		size_type unordered_erase(const K& key, std::size_t precalculated_hash) {
			return m_ht.unordered_erase(key, precalculated_hash);
		}



		friend bool operator==(const ordered_set& lhs, const ordered_set& rhs) { return lhs.m_ht == rhs.m_ht; }
		friend bool operator!=(const ordered_set& lhs, const ordered_set& rhs) { return lhs.m_ht != rhs.m_ht; }
		friend bool operator<(const ordered_set& lhs, const ordered_set& rhs) { return lhs.m_ht < rhs.m_ht; }
		friend bool operator<=(const ordered_set& lhs, const ordered_set& rhs) { return lhs.m_ht <= rhs.m_ht; }
		friend bool operator>(const ordered_set& lhs, const ordered_set& rhs) { return lhs.m_ht > rhs.m_ht; }
		friend bool operator>=(const ordered_set& lhs, const ordered_set& rhs) { return lhs.m_ht >= rhs.m_ht; }

		friend void swap(ordered_set& lhs, ordered_set& rhs) { lhs.swap(rhs); }

	private:
		ht m_ht;
};

} // end namespace tsl


namespace Poco {


template<class Key,
	class Hash = std::hash<Key>,
	class KeyEqual = std::equal_to<Key>,
	class Allocator = std::allocator<Key>,
	class ValueTypeContainer = std::deque<Key, Allocator>>
	using OrderedSet = tsl::ordered_set<Key, Hash, KeyEqual, Allocator, ValueTypeContainer>;

using DynamicStruct = Dynamic::Struct<std::string>;
using OrderedDynamicStruct = Dynamic::Struct<std::string, Poco::OrderedMap<std::string, Dynamic::Var>, Poco::OrderedSet<std::string>>;


} // namespace Poco

export module json_error:test;

export namespace Poco
{
	//using Poco::Struct;
	using Poco::DynamicStruct;
	using Poco::OrderedDynamicStruct;
	using Poco::OrderedMap;
	using Poco::OrderedSet;
	namespace Dynamic 
	{
	using Poco::Dynamic::Struct;
		using Poco::Dynamic::Var;
	}
}