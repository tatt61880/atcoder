#if 0 // Kuin Programming Language v.2021.6.17
func main()
	var n: int :: cui@inputInt()
	var m: int :: cui@inputInt()
	var graph: []list<Edge> :: #[n]list<Edge>
	for i(0, n - 1)
		do graph[i] :: #list<Edge>
	end for
	for i(0, m - 1)
		var a: int :: cui@inputInt() - 1
		var b: int :: cui@inputInt() - 1
		var c: int :: cui@inputInt()
		do graph[a].add((#Edge).init(b, c))
		do graph[b].add((#Edge).init(a, c))
	end for
	
	var dist1: []int :: dists(graph, 0)
	var distN: []int :: dists(graph, n - 1)
	
	for i(0, n - 1)
		var ans: int :: dist1[i] + distN[i]
		do cui@print("\{ans}\n")
	end for
	
	func dists(graph: []list<Edge>, start: int): []int
		var n: int :: ^graph
		var res: []int :: [lib@intMax].repeat(^graph)
		do res[start] :: 0
		var pq: PriorityQueue :: #PriorityQueue
		do pq.add(-(0 + start))
		while loop(pq.len <> 0)
			var data: int :: -pq.top()
			do pq.pop()
			var u: int :: data % n
			if(res[u] < data / n)
				skip loop
			end if
			
			do graph[u].head()
			for i(0, ^graph[u] - 1)
				var e: Edge :: graph[u].get()
				var v: int :: e.v
				var dist: int :: e.dist
				if(res[u] + dist < res[v])
					do res[v] :: res[u] + dist
					do pq.add(-(res[v] * n + v))
				end if
				do graph[u].next()
			end for
		end while
		ret res
		
		class PriorityQueue()
			var data: []int
			+var len: int
			*func ctor()
				do me.data :: #[1024]int
				do me.len :: 0
			end func
			+func add(elem: int)
				var n: int :: me.len
				if(^me.data = me.len)
					do me.data :~ #[me.len]int
				end if
				do me.data[me.len] :: elem
				do me.len :+ 1
				
				while(n <> 0)
					var i: int :: (n - 1) / 2
					if(me.data[n] > me.data[i])
						var tmp: int :: me.data[n]
						do me.data[n] :: me.data[i]
						do me.data[i] :: tmp
					end if
					do n :: i
				end while
			end func
			+func pop()
				var n: int :: me.len - 1
				do me.data[0] :: me.data[n]
				do me.len :- 1
				var i: int :: 0
				var j: int :: 1
				while(j < n)
					if(j <> n - 1 & me.data[j] < me.data[j + 1])
						do j :+ 1
					end if
					if(me.data[i] < me.data[j])
						var tmp: int :: me.data[j]
						do me.data[j] :: me.data[i]
						do me.data[i] :: tmp
					end if
					do i :: j
					do j :: 2 * i + 1
				end while
			end func
			+func top(): int
				ret me.data[0]
			end func
		end class
	end func
	
	class Edge()
		+var v: int
		+var dist: int
		+func init(v: int, dist: int): Edge
			do me.v :: v
			do me.dist :: dist
			ret me
		end func
	end class
end func
#endif

//{{{ C++ code below is transpiled from Kuin code above by Kuin Programming Language v.2021.6.17
#if defined(_WIN32)
#define _CRT_SECURE_NO_WARNINGS
#else
#define _FILE_OFFSET_BITS 64
#endif
#include <cstddef>
#include <cstdint>
static int64_t classTable_[41];
#include <memory>
#define new_(...) std::make_shared<__VA_ARGS__>
#define type_(...) std::shared_ptr<__VA_ARGS__>
#define newPrim_(...) new __VA_ARGS__
#define delPrim_(x) delete x
#define newPrimArray_(x, ...) new __VA_ARGS__[x]
#define delPrimArray_(x) delete[] x
#define dcast_(...) std::dynamic_pointer_cast<__VA_ARGS__>
#define addr_(...) (__VA_ARGS__==nullptr?0:reinterpret_cast<uint64_t>(__VA_ARGS__.get()))
#include <algorithm>
#include <chrono>
#include <cmath>
#include <codecvt>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <sys/stat.h>
#include <type_traits>
#include <vector>

namespace {
	template<typename T> std::size_t bufLen_() { return 0; }
	template<> std::size_t bufLen_<char16_t>() { return 1; }
}
static int64_t exitCode_ = 0;

struct Class_ {
	Class_() : Y(0LL) {}
	virtual ~Class_() {}
	int64_t Y;
};
template<typename T> struct Array_ {
	Array_() : L(), B() {}
	template<typename... A>
	explicit Array_(A... a) {
		L = sizeof...(a);
		B = newPrimArray_(static_cast<std::size_t>(sizeof...(a) + bufLen_<T>()), T);
		BufferCopy(B, std::forward<A>(a)...);
		if (bufLen_<T>() > 0)
			B[sizeof...(a)] = 0;
	}
	~Array_() {
		delPrimArray_(B);
	}
	void BufferCopy(T* b) {}
	template<typename A, typename... B>
	void BufferCopy(T* b, A h, B... t) {
		*b = h;
		BufferCopy(b + 1, std::forward<B>(t)...);
	}
	type_(Array_<T>) Cat(const type_(Array_<T>) t) {
		type_(Array_<T>) r = new_(Array_<T>)();
		r->B = newPrimArray_(static_cast<std::size_t>(L + t->L + bufLen_<T>()), T);
		for (int64_t i = 0; i < L; i++)
			r->B[i] = B[i];
		for (int64_t i = 0; i < static_cast<int64_t>(t->L + bufLen_<T>()); i++)
			r->B[L + i] = t->B[i];
		r->L = L + t->L;
		return r;
	}
	int64_t Len() { return L; }
	T& At(int64_t n) {
		if (n < 0 || n >= L) throw 0xe9170002;
		return B[n];
	}
	int64_t L;
	T* B;
};
template<typename T> struct List_ {
	List_() : B(), I(B.end()) {}
	int64_t Len() { return static_cast<int64_t>(B.size()); }
	std::list<T> B;
	typename std::list<T>::iterator I;
};
template<typename T> struct Stack_ {
	Stack_() : B() {}
	int64_t Len() { return static_cast<int64_t>(B.size()); }
	std::stack<T> B;
};
template<typename T> struct Queue_ {
	Queue_() : B() {}
	int64_t Len() { return static_cast<int64_t>(B.size()); }
	std::queue<T> B;
};
template<typename T1, typename T2> struct dictImpl_;
template<typename T1, typename T2> dictImpl_<T1, T2>* dictAddRec_(dictImpl_<T1, T2>* n, T1 k, T2 v, bool* a);
template<typename T1, typename T2> dictImpl_<T1, T2>* dictDelRec_(dictImpl_<T1, T2>* n, T1 k, bool* d);
template<typename T1, typename T2> dictImpl_<T1, T2>* dictCopyRec_(dictImpl_<T1, T2>* n);
template<typename T1, typename T2> void dictToBinRec_(type_(Array_<uint8_t>) a, dictImpl_<T1, T2>* d);
template<typename T1, typename T2> void dictFreeRec_(dictImpl_<T1, T2>* n);
template<typename T1, typename T2> struct Dict_ {
	Dict_() : L(0LL), B(nullptr) {}
	~Dict_() {
		dictFreeRec_<T1, T2>(B);
	}
	int64_t Len() { return L; }
	void Add(T1 k, T2 v) {
		bool a = false;
		B = dictAddRec_<T1, T2>(B, k, v, &a);
		B->R = false;
		if (a)
			L++;
	}
	void Del(T1 k) {
		bool d = false;
		B = dictDelRec_<T1, T2>(B, k, &d);
		if (B != nullptr)
			B->R = false;
		if (d)
			L--;
	}
	int64_t L;
	dictImpl_<T1, T2>* B;
};
template<typename T1, typename T2> struct dictImpl_ {
	dictImpl_(T1 k, T2 v) : K(k), V(v), CL(nullptr), CR(nullptr), R(true) {}
	T1 K;
	T2 V;
	dictImpl_* CL;
	dictImpl_* CR;
	bool R;
};

#if _MSC_VER >= 1900 && _MSC_VER < 1922
static std::string utf16ToUtf8_(const std::u16string& s) {
	const int16_t* p = reinterpret_cast<const int16_t*>(s.data());
	return std::wstring_convert<std::codecvt_utf8_utf16<int16_t>, int16_t>{}.to_bytes(p, p + s.size());
}
static std::u16string utf8ToUtf16_(const std::string& s) {
	const auto t = std::wstring_convert<std::codecvt_utf8_utf16<int16_t>, int16_t>{}.from_bytes(s);
	return std::u16string(reinterpret_cast<const char16_t*>(t.data()), t.size());
}
#else
static std::string utf16ToUtf8_(const std::u16string& s) {
	return std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t>{}.to_bytes(s);
}
static std::u16string utf8ToUtf16_(const std::string& s) {
	return std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t>{}.from_bytes(s);
}
#endif

#if defined(_WIN32)

#pragma comment(lib, "shlwapi.lib")
#define STRICT
#define _WIN32_DCOM
#include <Windows.h>
#include <Shlwapi.h>
#include <io.h>

const char newLine_[] = { '\r', '\n' };

static void normPath_(char16_t* p, bool d) {
	if (*p == 0)
		return;
	do
	{
		if (*p == '\\')
			*p = '/';
		p++;
	} while (*p != 0);
	if (d && p[-1] != '/')
	{
		p[0] = '/';
		p[1] = 0;
	}
}

static bool fileExists_(const char16_t* p) {
	return PathFileExistsW(reinterpret_cast<const wchar_t*>(p)) != 0;
}
static int64_t getCurDir_(char16_t* p) {
	if (!::GetCurrentDirectoryW(511, reinterpret_cast<wchar_t*>(p)))
		return 0;
	normPath_(p, true);
	return ::wcslen(reinterpret_cast<wchar_t*>(p));
}
static void setCurDir_(const char16_t* p) {
	::SetCurrentDirectoryW(reinterpret_cast<const wchar_t*>(p));
}
static bool makeDir_(const char16_t* p) {
	return ::CreateDirectoryW(reinterpret_cast<const wchar_t*>(p), 0) != 0;
}
static bool delFile_(const char16_t* p) {
	if (!PathFileExistsW(reinterpret_cast<const wchar_t*>(p)))
		return true;
	return ::DeleteFileW(reinterpret_cast<const wchar_t*>(p)) != 0;
}
static bool copyFile_(const char16_t* d, const char16_t* s) {
	return ::CopyFileW(reinterpret_cast<const wchar_t*>(s), reinterpret_cast<const wchar_t*>(d), false) != 0;
}
static bool moveFile_(const char16_t* d, const char16_t* s) {
	return ::MoveFileExW(reinterpret_cast<const wchar_t*>(s), reinterpret_cast<const wchar_t*>(d), MOVEFILE_COPY_ALLOWED | MOVEFILE_WRITE_THROUGH | MOVEFILE_REPLACE_EXISTING) != 0;
}
static int64_t fullPath_(char16_t* p, const char16_t* q) {
	wchar_t* f;
	if (!::GetFullPathNameW(reinterpret_cast<const wchar_t*>(q), 511, reinterpret_cast<wchar_t*>(p), &f))
		return 0;
	normPath_(p, q[::wcslen(reinterpret_cast<const wchar_t*>(q)) - 1] == '/');
	return ::wcslen(reinterpret_cast<wchar_t*>(p));
}
static void sleep_(int64_t t) {
	for (int64_t i = 0; i < t / 10000; i++)
		Sleep(10000);
	Sleep(static_cast<DWORD>(t % 10000));
}

#else

#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#define _A_SUBDIR 0x10

const char newLine_[] = { '\n' };

static void normPath_(char* p, bool d) {
	if (*p == 0)
		return;
	std::size_t l = ::strlen(p);
	if (d && p[l - 1] != '/')
	{
		p[l] = '/';
		p[l + 1] = 0;
	}
}

static bool fileExists_(const char16_t* p) {
	struct stat b;
	std::u16string s = p;
	const std::string& t = utf16ToUtf8_(s);
	return ::stat(t.c_str(), &b) == 0;
}
static int64_t getCurDir_(char16_t* p) {
	char b[512];
	if (getcwd(b, 511) == nullptr)
		return 0;
	normPath_(b, true);
	std::string s = b;
	const std::u16string& t = utf8ToUtf16_(s);
	if (t.size() >= 512)
		return 0;
	memcpy(p, t.c_str(), sizeof(char16_t) * (t.size() + 1));
	return static_cast<int64_t>(t.size());
}
static void setCurDir_(const char16_t* p) {
	std::u16string s = p;
	const std::string& t = utf16ToUtf8_(s);
	::chdir(t.c_str());
}
static bool makeDir_(const char16_t* p) {
	std::u16string s = p;
	const std::string& t = utf16ToUtf8_(s);
	return ::mkdir(t.c_str(), S_IRWXU | S_IRWXG | S_IRWXO) == 0;
}
static bool delFile_(const char16_t* p) {
	struct stat b;
	std::u16string s = p;
	const std::string& t = utf16ToUtf8_(s);
	if (::stat(t.c_str(), &b) != 0)
		return true;
	return ::unlink(t.c_str()) == 0;
}
static bool copyFile_(const char16_t* d, const char16_t* s) {
	std::u16string s1 = d;
	const std::string& t1 = utf16ToUtf8_(s1);
	std::u16string s2 = s;
	const std::string& t2 = utf16ToUtf8_(s2);
	int i = ::open(t2.c_str(), O_RDONLY);
	if (i < 0)
		return false;
	struct stat f;
	if (::stat(t2.c_str(), &f) != 0)
	{
		::close(i);
		return false;
	}
	int o = ::open(t1.c_str(), O_CREAT | O_WRONLY | O_TRUNC, f.st_mode);
	if (o < 0)
	{
		::close(i);
		return false;
	}
	ssize_t r = 1;
	char* buf = newPrimArray_(65536, char);
	while (r > 0 && (r = ::read(i, buf, 65536)) > 0)
	{
		ssize_t z, w = 0;
		do
		{
			if ((z = ::write(o, buf + w, r - w)) < 0)
			{
				r = z;
				break;
			}
			w += z;
		} while (w < r);
	}
	if (::close(i) < 0)
		r = -1;
	if (::close(o) < 0)
		r = -1;
	delPrimArray_(buf);
	return r >= 0;
}
static bool moveFile_(const char16_t* d, const char16_t* s) {
	std::u16string s1 = d;
	const std::string& t1 = utf16ToUtf8_(s1);
	std::u16string s2 = s;
	const std::string& t2 = utf16ToUtf8_(s2);
	struct stat b;
	if (::stat(t1.c_str(), &b) == 0)
	{
		if (::unlink(t1.c_str()) != 0)
			return false;
	}
	return ::rename(t2.c_str(), t1.c_str()) == 0;
}
static int64_t fullPath_(char16_t* p, const char16_t* q) {
	std::u16string s1 = q;
	const std::string& t1 = utf16ToUtf8_(s1);
	char a[512 + 1];
	if (::realpath(t1.c_str(), a) == nullptr)
		return 0;
	normPath_(a, t1[t1.size() - 1] == '/');
	std::string s2 = a;
	const std::u16string& t2 = utf8ToUtf16_(s2);
	if (t2.size() >= 512)
		return 0;
	memcpy(p, t2.c_str(), sizeof(char16_t) * (t2.size() + 1));
	return static_cast<int64_t>(t2.size());
}
static void sleep_(int64_t t) {
	timespec r = { t / 1000, t % 1000 * 1000000 };
	nanosleep(&r, nullptr);
}

#endif

static bool fileForEach_(const std::u16string& p, bool r, bool(*f)(type_(Array_<char16_t>), bool, type_(Class_)), type_(Class_) d) {
	if (p.size() > 512)
		return false;
#if defined(_WIN32)
	WIN32_FIND_DATAW t;
	HANDLE h;
#else
	dirent* t;
	DIR* h;
#endif
	bool a = true;
	{
#if defined(_WIN32)
		wchar_t p3[514];
		memcpy(p3, p.c_str(), sizeof(wchar_t) * static_cast<std::size_t>(p.size()));
		p3[p.size()] = '*';
		p3[p.size() + 1] = 0;
		h = FindFirstFileW(p3, &t);
		if (h == INVALID_HANDLE_VALUE)
			return false;
#else
		const std::string& p2 = utf16ToUtf8_(p);
		h = ::opendir(p2.c_str());
		if (h == nullptr)
			return false;
#endif
	}
	{
		type_(Array_<char16_t>) x = new_(Array_<char16_t>)();
		x->L = static_cast<int64_t>(p.size());
		x->B = newPrimArray_(static_cast<std::size_t>(p.size() + 1), char16_t);
		memcpy(x->B, p.c_str(), sizeof(char16_t) * static_cast<std::size_t>(p.size() + 1));
		if (!f(x, true, d))
			a = false;
	}
	if (a) {
#if defined(_WIN32)
		do {
			wchar_t* b = t.cFileName;
			if ((t.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0) {
				std::size_t l = ::wcslen(b);
#else
		while ((t = readdir(h)) != nullptr) {
			if ((t->d_type & _A_SUBDIR) == 0) {
				std::string s = t->d_name;
				const std::u16string& p2 = utf8ToUtf16_(s);
				std::size_t l = p2.size();
				const char16_t* b = p2.c_str();
#endif
				type_(Array_<char16_t>) p3 = new_(Array_<char16_t>)();
				p3->L = p.size() + static_cast<int64_t>(l);
				p3->B = newPrimArray_(static_cast<std::size_t>(p.size() + l + 1), char16_t);
				memcpy(p3->B, p.c_str(), sizeof(char16_t) * static_cast<std::size_t>(p.size()));
				memcpy(p3->B + p.size(), b, sizeof(char16_t) * (l + 1));
				if (!f(p3, false, d))
				{
					a = false;
					break;
				}
			}
			else if (r) {
				std::u16string p3 = p;
#if defined(_WIN32)
				if (wcscmp(b, L".") == 0 || wcscmp(b, L"..") == 0)
					continue;
				p3 += reinterpret_cast<const char16_t*>(b);

#else
				const char* n = t->d_name;
				if (strcmp(n, ".") == 0 || strcmp(n, "..") == 0)
					continue;
				std::string s = n;
				const std::u16string& p2 = utf8ToUtf16_(s);
				p3 += p2;
#endif
				p3 += u'/';
				if (!fileForEach_(p3, r, f, d))
				{
					a = false;
					break;
				}
			}
		}
#if defined(_WIN32)
		while (FindNextFileW(h, &t));
#endif
	}
#if defined(_WIN32)
	FindClose(h);
#else
	closedir(h);
#endif
	return a;
}

static bool delDir_(const std::u16string& p) {
	if (p.size() > 512)
		return false;
	if (!fileExists_(p.c_str()))
		return true;
#if defined(_WIN32)
	WIN32_FIND_DATAW t;
	HANDLE h;
#else
	dirent* t;
	DIR* h;
#endif
	bool a = true;
	{
#if defined(_WIN32)
		wchar_t p3[514];
		memcpy(p3, p.c_str(), sizeof(wchar_t) * static_cast<std::size_t>(p.size()));
		p3[p.size()] = '*';
		p3[p.size() + 1] = 0;
		h = FindFirstFileW(p3, &t);
		if (h == INVALID_HANDLE_VALUE)
			return false;
#else
		const std::string& p2 = utf16ToUtf8_(p);
		h = ::opendir(p2.c_str());
		if (h == nullptr)
			return false;
#endif
	}
#if defined(_WIN32)
	do {
		if ((t.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0) {
			std::u16string b = p;
			b += reinterpret_cast<const char16_t*>(t.cFileName);
#else
	while ((t = readdir(h)) != nullptr) {
		if ((t->d_type & _A_SUBDIR) == 0) {
			std::string n = t->d_name;
			const std::u16string& n2 = utf8ToUtf16_(n);
			std::u16string b = p;
			b += n2;
#endif
			if (!delFile_(b.c_str()))
			{
				a = false;
				break;
			}
		} else {
			std::u16string p2 = p;
#if defined(_WIN32)
			const wchar_t* n = t.cFileName;
			if (wcscmp(n, L".") == 0 || wcscmp(n, L"..") == 0)
				continue;
			p2 += reinterpret_cast<const char16_t*>(n);
#else
			const char* n = t->d_name;
			if (strcmp(n, ".") == 0 || strcmp(n, "..") == 0)
				continue;
			std::string s = n;
			const std::u16string& n2 = utf8ToUtf16_(s);
			p2 += n2;
#endif
			p2 += u"/";
			if (!delDir_(p2))
			{
				a = false;
				break;
			}
		}
	}
#if defined(_WIN32)
	while (FindNextFileW(h, &t));
	FindClose(h);
#else
	closedir(h);
#endif
	if (a) {
#if defined(_WIN32)
		a = ::RemoveDirectoryW(reinterpret_cast<const wchar_t*>(p.c_str())) != 0;
#else
		const std::string& p2 = utf16ToUtf8_(p);
		a = ::rmdir(p2.c_str()) == 0;
#endif
	}
	return a;
}

static bool copyDir_(const std::u16string& d, const std::u16string& s) {
	if (s.size() > 512)
		return false;
#if defined(_WIN32)
	WIN32_FIND_DATAW t;
	HANDLE h;
#else
	dirent* t;
	DIR* h;
#endif
	bool a = true;
	{
#if defined(_WIN32)
		wchar_t p3[514];
		memcpy(p3, s.c_str(), sizeof(wchar_t) * static_cast<std::size_t>(s.size()));
		p3[s.size()] = '*';
		p3[s.size() + 1] = 0;
		h = FindFirstFileW(p3, &t);
		if (h == INVALID_HANDLE_VALUE)
			return false;
#else
		const std::string& p2 = utf16ToUtf8_(s);
		h = ::opendir(p2.c_str());
		if (h == nullptr)
			return false;
#endif
	}
	if (!fileExists_(d.c_str()))
	{
		if (!makeDir_(d.c_str()))
			a = false;
	}
	if (a) {
#if defined(_WIN32)
		do {
			if ((t.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0) {
				std::u16string s2 = s;
				s2 += reinterpret_cast<const char16_t*>(t.cFileName);
				std::u16string d2 = d;
				d2 += reinterpret_cast<const char16_t*>(t.cFileName);
#else
		while ((t = readdir(h)) != nullptr) {
			if ((t->d_type & _A_SUBDIR) == 0) {
				std::string n = t->d_name;
				const std::u16string& n2 = utf8ToUtf16_(n);
				std::u16string s2 = s;
				s2 += n2;
				std::u16string d2 = d;
				d2 += n2;
#endif
				if (!copyFile_(d2.c_str(), s2.c_str()))
				{
					a = false;
					break;
				}
			}
			else {
				std::u16string s2 = s;
				std::u16string d2 = d;
#if defined(_WIN32)
				const wchar_t* n = t.cFileName;
				if (wcscmp(n, L".") == 0 || wcscmp(n, L"..") == 0)
					continue;
				s2 += reinterpret_cast<const char16_t*>(n);
				d2 += reinterpret_cast<const char16_t*>(n);
#else
				const char* n = t->d_name;
				if (strcmp(n, ".") == 0 || strcmp(n, "..") == 0)
					continue;
				std::string t = n;
				const std::u16string& n2 = utf8ToUtf16_(t);
				s2 += n2;
				d2 += n2;
#endif
				s2 += u"/";
				d2 += u"/";
				if (!copyDir_(d2, s2))
				{
					a = false;
					break;
				}
			}
		}
#if defined(_WIN32)
		while (FindNextFileW(h, &t));
#endif
	}
#if defined(_WIN32)
	FindClose(h);
#else
	closedir(h);
#endif
	return a;
}

static bool moveDir_(const char16_t* d, const char16_t* s) {
#if defined(_WIN32)
	if (::MoveFileExW(reinterpret_cast<const wchar_t*>(s), reinterpret_cast<const wchar_t*>(d), MOVEFILE_COPY_ALLOWED | MOVEFILE_WRITE_THROUGH | MOVEFILE_REPLACE_EXISTING))
		return true;
#endif
	std::u16string d2 = d;
	std::u16string s2 = s;
	if (!copyDir_(d2, s2))
		return false;
	if (!delDir_(s2))
		return false;
	return true;
}

static bool makeDir2_(const char16_t* p) {
	char16_t b[512];
	int64_t l = fullPath_(b, p);
	if (l == 0)
		return false;
	const char16_t* q = b;
	while (*q != 0){
		while (*q != '/')
			q++;
		char16_t a[512];
		memcpy(a, b, sizeof(char16_t) * static_cast<std::size_t>(q - b + 1));
		a[q - b + 1] = 0;
		if (!fileExists_(a))
		{
			if (!makeDir_(a))
				return false;
		}
		q++;
	}
	return true;
}

template<typename T> struct newArraysRec_ {
	T operator()() { throw 0; }
	template<typename A, typename... B> T operator()(A h, B... t) { throw 0; }
};
template<typename T> struct newArraysRec_<type_(Array_<T>)> {
	type_(Array_<T>) operator()() { throw 0; }
	template<typename A, typename... C> type_(Array_<T>) operator()(A h, C... t) {
		if (h < 0) throw 0xe917000b;
		type_(Array_<T>) r = new_(Array_<T>)();
		r->L = h;
		r->B = newPrimArray_(static_cast<std::size_t>(h + bufLen_<T>()), T);
		if (sizeof...(t) == 0)
			memset(r->B, 0, sizeof(T) * static_cast<std::size_t>(h + bufLen_<T>()));
		else
		{
			for (int64_t i = 0; i < h; i++)
				r->B[i] = newArraysRec_<T>()(std::forward<C>(t)...);
		}
		return r;
	}
};
template<typename T, typename... A> T newArrays_(A... a) {
	if (sizeof...(a) > 64)
		return nullptr;
	return newArraysRec_<T>()(std::forward<A>(a)...);
}
template<typename T>
type_(Array_<T>) newArrayBin_(int64_t l, const void* d) {
	type_(Array_<T>) r = new_(Array_<T>)();
	r->L = l;
	r->B = newPrimArray_(static_cast<std::size_t>(l) + bufLen_<T>(), T);
	memcpy(r->B, d, sizeof(T) * static_cast<std::size_t>(l));
	if (bufLen_<T>() > 0)
		r->B[l] = 0;
	return r;
}

template<typename T> type_(Array_<T>) toArray_(type_(List_<T>) l) {
	type_(Array_<T>) a = new_(Array_<T>)();
	a->L = l->Len();
	a->B = newPrimArray_(static_cast<std::size_t>(a->L) + bufLen_<T>(), T);
	int64_t i = 0;
	for (auto& e : l->B)
	{
		a->B[i] = e;
		i++;
	}
	if (bufLen_<T>() > 0)
		a->B[a->L] = 0;
	return a;
}

template<typename T> struct copy_ {};
template<typename T> struct copy_<type_(Array_<T>)> {
	type_(Array_<T>) operator()(type_(Array_<T>) t) {
		if (t == nullptr)
			return nullptr;
		type_(Array_<T>) r = new_(Array_<T>)();
		r->L = t->L;
		r->B = newPrimArray_(static_cast<std::size_t>(t->L) + bufLen_<T>(), T);
		for (int64_t i = 0; i < t->L; i++)
			r->B[i] = copy_<T>()(t->B[i]);
		if (bufLen_<T>() > 0)
			r->B[r->L] = 0;
		return r;
	}
};
template<typename T> struct copy_<type_(List_<T>)> {
	type_(List_<T>) operator()(type_(List_<T>) t) {
		if (t == nullptr)
			return nullptr;
		type_(List_<T>) r = new_(List_<T>)();
		for (auto i = t->B.begin(); i != t->B.end(); ++i)
		{
			r->B.push_back(copy_<T>()(*i));
			if (i == t->I)
			{
				auto e = r->B.end();
				--e;
				r->I = e;
			}
		}
		return r;
	}
};
template<typename T> struct copy_<type_(Stack_<T>)> {
	type_(Stack_<T>) operator()(type_(Stack_<T>) t) {
		if (t == nullptr)
			return nullptr;
		type_(Stack_<T>) r = new_(Stack_<T>)();
		std::stack<T> b;
		while (!t->B.empty())
		{
			b.push(t->B.top());
			t->B.pop();
		}
		while (!b.empty())
		{
			r->B.push(copy_<T>()(b.top()));
			t->B.push(b.top());
			b.pop();
		}
		return r;
	}
};
template<typename T> struct copy_<type_(Queue_<T>)> {
	type_(Queue_<T>) operator()(type_(Queue_<T>) t) {
		if (t == nullptr)
			return nullptr;
		type_(Queue_<T>) r = new_(Queue_<T>)();
		std::queue<T> b;
		while (!t->B.empty())
		{
			b.push(t->B.front());
			t->B.pop();
		}
		while (!b.empty())
		{
			r->B.push(copy_<T>()(b.front()));
			t->B.push(b.front());
			b.pop();
		}
		return r;
	}
};
template<typename T1, typename T2> struct copy_<type_(Dict_<T1, T2>)> {
	type_(Dict_<T1, T2>) operator()(type_(Dict_<T1, T2>) t) {
		if (t == nullptr)
			return nullptr;
		type_(Dict_<T1, T2>) r = new_(Dict_<T1, T2>)();
		r->L = t->L;
		r->B = dictCopyRec_<T1, T2>(t->B);
		return r;
	}
};
template<typename T> struct copy_<type_(T)> {
	type_(T) operator()(type_(T) t) {
		if (std::is_class<T>::value)
		{
			if (t == nullptr)
				return nullptr;
			return dcast_(T)(reinterpret_cast<type_(Class_)(*)(type_(Class_))>(classTable_[t->Y + 4])(t));
		}
		else
			return t;
	}
};
template<> struct copy_ <int64_t> { int64_t operator()(int64_t t) { return t; } };
template<> struct copy_ <char16_t> { char16_t operator()(char16_t t) { return t; } };
template<> struct copy_ <bool> { bool operator()(bool t) { return t; } };
template<> struct copy_ <double> { double operator()(double t) { return t; } };
template<> struct copy_ <uint8_t> { uint8_t operator()(uint8_t t) { return t; } };
template<> struct copy_ <uint16_t> { uint16_t operator()(uint16_t t) { return t; } };
template<> struct copy_ <uint32_t> { uint32_t operator()(uint32_t t) { return t; } };
template<> struct copy_ <uint64_t> { uint64_t operator()(uint64_t t) { return t; } };

static type_(Array_<char16_t>) toStr_(int64_t v) {
	std::stringstream s;
	s << v;
	const std::string& t = s.str();
	type_(Array_<char16_t>) r = new_(Array_<char16_t>)();
	r->L = static_cast<int64_t>(t.size());
	r->B = newPrimArray_(t.size() + 1, char16_t);
	int64_t p = 0;
	for (char c : t)
		r->B[p++] = c;
	r->B[t.size()] = 0;
	return r;
}
static type_(Array_<char16_t>) toStr_(char16_t v) {
	type_(Array_<char16_t>) r = new_(Array_<char16_t>)();
	r->L = static_cast<int64_t>(1);
	r->B = newPrimArray_(2, char16_t);
	r->B[0] = v;
	r->B[1] = 0;
	return r;
}
static type_(Array_<char16_t>) toStr_(bool v) {
	type_(Array_<char16_t>) r = new_(Array_<char16_t>)();
	if (v)
	{
		r->L = static_cast<int64_t>(4);
		r->B = newPrimArray_(5, char16_t);
		r->B[0] = 't';
		r->B[1] = 'r';
		r->B[2] = 'u';
		r->B[3] = 'e';
		r->B[4] = 0;
	}
	else
	{
		r->L = static_cast<int64_t>(5);
		r->B = newPrimArray_(6, char16_t);
		r->B[0] = 'f';
		r->B[1] = 'a';
		r->B[2] = 'l';
		r->B[3] = 's';
		r->B[4] = 'e';
		r->B[5] = 0;
	}
	return r;
}
static type_(Array_<char16_t>) toStr_(double v) {
	std::stringstream s;
	s << std::setprecision(16) << v;
	const std::string& t = s.str();
	type_(Array_<char16_t>) r = new_(Array_<char16_t>)();
	r->L = static_cast<int64_t>(t.size());
	r->B = newPrimArray_(t.size() + 1, char16_t);
	int64_t p = 0;
	for (char c : t)
		r->B[p++] = c;
	r->B[t.size()] = 0;
	return r;
}
static type_(Array_<char16_t>) toStr_(uint8_t v) {
	std::stringstream s;
	s << "0x" << std::uppercase << std::setfill('0') << std::setw(2) << std::hex << static_cast<uint16_t>(v);
	const std::string& t = s.str();
	type_(Array_<char16_t>) r = new_(Array_<char16_t>)();
	r->L = static_cast<int64_t>(t.size());
	r->B = newPrimArray_(t.size() + 1, char16_t);
	int64_t p = 0;
	for (char c : t)
		r->B[p++] = c;
	r->B[t.size()] = 0;
	return r;
}
static type_(Array_<char16_t>) toStr_(uint16_t v) {
	std::stringstream s;
	s << "0x" << std::uppercase << std::setfill('0') << std::setw(4) << std::hex << v;
	const std::string& t = s.str();
	type_(Array_<char16_t>) r = new_(Array_<char16_t>)();
	r->L = static_cast<int64_t>(t.size());
	r->B = newPrimArray_(t.size() + 1, char16_t);
	int64_t p = 0;
	for (char c : t)
		r->B[p++] = c;
	r->B[t.size()] = 0;
	return r;
}
static type_(Array_<char16_t>) toStr_(uint32_t v) {
	std::stringstream s;
	s << "0x" << std::uppercase << std::setfill('0') << std::setw(8) << std::hex << v;
	const std::string& t = s.str();
	type_(Array_<char16_t>) r = new_(Array_<char16_t>)();
	r->L = static_cast<int64_t>(t.size());
	r->B = newPrimArray_(t.size() + 1, char16_t);
	int64_t p = 0;
	for (char c : t)
		r->B[p++] = c;
	r->B[t.size()] = 0;
	return r;
}
static type_(Array_<char16_t>) toStr_(uint64_t v) {
	std::stringstream s;
	s << "0x" << std::uppercase << std::setfill('0') << std::setw(16) << std::hex << v;
	const std::string& t = s.str();
	type_(Array_<char16_t>) r = new_(Array_<char16_t>)();
	r->L = static_cast<int64_t>(t.size());
	r->B = newPrimArray_(t.size() + 1, char16_t);
	int64_t p = 0;
	for (char c : t)
		r->B[p++] = c;
	r->B[t.size()] = 0;
	return r;
}
static type_(Array_<char16_t>) toStr_(type_(Array_<char16_t>) v) {
	return v;
}

static int64_t cmp_(type_(Array_<char16_t>) a, type_(Array_<char16_t>) b) {
	int64_t p = 0;
	while (p < a->L && p < b->L)
	{
		if (a->B[p] != b->B[p])
			return a->B[p] > b->B[p] ? 1 : (a->B[p] < b->B[p] ? -1 : 0);
		p++;
	}
	return a->L > b->L ? 1 : (a->L < b->L ? -1 : 0);
}
static int64_t cmp_(type_(Class_) a, type_(Class_) b) { return reinterpret_cast<int64_t(*)(type_(Class_), type_(Class_))>(classTable_[a->Y + 3])(a, b); }
static int64_t cmp_(int64_t a, int64_t b) { return a - b; }
static int64_t cmp_(char16_t a, char16_t b) { return static_cast<int64_t>(a) - static_cast<int64_t>(b); }
static int64_t cmp_(double a, double b) { return a > b ? 1LL : (a < b ? -1LL : 0LL); }
static int64_t cmp_(uint8_t a, uint8_t b) { return static_cast<int64_t>(a) - static_cast<int64_t>(b); }
static int64_t cmp_(uint16_t a, uint16_t b) { return static_cast<int64_t>(a) - static_cast<int64_t>(b); }
static int64_t cmp_(uint32_t a, uint32_t b) { return static_cast<int64_t>(a) - static_cast<int64_t>(b); }
static int64_t cmp_(uint64_t a, uint64_t b) { return a > b ? 1LL : (a < b ? -1LL : 0LL); }

static type_(Array_<uint8_t>) makeBin_(const void* v, std::size_t s) {
	type_(Array_<uint8_t>) r = new_(Array_<uint8_t>)();
	r->L = s;
	r->B = newPrimArray_(s, uint8_t);
	memcpy(r->B, v, s);
	return r;
}
static void mergeBin_(type_(Array_<uint8_t>) a, const type_(Array_<uint8_t>) b) {
	int64_t l = a->L + b->L;
	uint8_t* d = newPrimArray_(static_cast<std::size_t>(l), uint8_t);
	memcpy(d, a->B, static_cast<std::size_t>(a->L));
	memcpy(d + a->L, b->B, static_cast<std::size_t>(b->L));
	a->L = l;
	a->B = d;
}
template<typename T> struct toBin_ {};
template<typename T> struct toBin_<type_(Array_<T>)> {
	type_(Array_<uint8_t>) operator()(type_(Array_<T>) v) {
		if (v == nullptr) { int64_t p = -1; return makeBin_(&p, sizeof(p)); }
		type_(Array_<uint8_t>) r = makeBin_(&v->L, sizeof(int64_t));
		for (int64_t i = 0; i < v->L; i++)
			mergeBin_(r, toBin_<T>()(v->B[i]));
		return r;
	}
};
template<typename T> struct toBin_<type_(List_<T>)> {
	type_(Array_<uint8_t>) operator()(type_(List_<T>) v) {
		if (v == nullptr) { int64_t p = -1; return makeBin_(&p, sizeof(p)); }
		int64_t s = static_cast<int64_t>(v->B.size());
		type_(Array_<uint8_t>) r = makeBin_(&s, sizeof(int64_t));
		int64_t c = 0, d = -1;
		for (auto i = v->B.begin(); i != v->B.end(); ++i, ++c) if (i == v->I) { d = c; break; }
		mergeBin_(r, makeBin_(&d, sizeof(int64_t)));
		for (auto& n : v->B)
			mergeBin_(r, toBin_<T>()(n));
		return r;
	}
};
template<typename T> struct toBin_<type_(Stack_<T>)> {
	type_(Array_<uint8_t>) operator()(type_(Stack_<T>) v) {
		if (v == nullptr) { int64_t p = -1; return makeBin_(&p, sizeof(p)); }
		int64_t s = static_cast<int64_t>(v->B.size());
		std::stack<T> b;
		type_(Array_<uint8_t>) r = makeBin_(&s, sizeof(int64_t));
		while (!v->B.empty())
		{
			b.push(v->B.top());
			v->B.pop();
		}
		while (!b.empty())
		{
			T n = b.top();
			mergeBin_(r, toBin_<T>()(n));
			v->B.push(n);
			b.pop();
		}
		return r;
	}
};
template<typename T> struct toBin_<type_(Queue_<T>)> {
	type_(Array_<uint8_t>) operator()(type_(Queue_<T>) v) {
		if (v == nullptr) { int64_t p = -1; return makeBin_(&p, sizeof(p)); }
		int64_t s = static_cast<int64_t>(v->B.size());
		std::queue<T> b;
		type_(Array_<uint8_t>) r = makeBin_(&s, sizeof(int64_t));
		while (!v->B.empty())
		{
			T n = v->B.front();
			b.push(n);
			mergeBin_(r, toBin_<T>()(n));
			v->B.pop();
		}
		while (!b.empty())
		{
			v->B.push(b.front());
			b.pop();
		}
		return r;
	}
};
template<typename T1, typename T2> struct toBin_<type_(Dict_<T1, T2>)> {
	type_(Array_<uint8_t>) operator()(type_(Dict_<T1, T2>) v) {
		if (v == nullptr) { int64_t p = -1; return makeBin_(&p, sizeof(p)); }
		type_(Array_<uint8_t>) r = makeBin_(&v->L, sizeof(int64_t));
		dictToBinRec_<T1, T2>(r, v->B);
		return r;
	}
};
template<typename T> struct toBin_<type_(T)> {
	type_(Array_<uint8_t>) operator()(type_(T) v) {
		if (v == nullptr) { int64_t p = -1; return makeBin_(&p, sizeof(p)); }
		auto w = dcast_(Class_)(v);
		type_(Array_<uint8_t>) r = makeBin_(&w->Y, sizeof(int64_t));
		mergeBin_(r, reinterpret_cast<type_(Array_<uint8_t>)(*)(type_(Class_))>(classTable_[w->Y + 5])(w));
		return r;
	}
};
template<> struct toBin_<int64_t> { type_(Array_<uint8_t>) operator()(int64_t v) { return makeBin_(&v, sizeof(v)); } };
template<> struct toBin_<double> { type_(Array_<uint8_t>) operator()(double v) { return makeBin_(&v, sizeof(v)); } };
template<> struct toBin_<char16_t> { type_(Array_<uint8_t>) operator()(char16_t v) { return makeBin_(&v, sizeof(v)); } };
template<> struct toBin_<bool> { type_(Array_<uint8_t>) operator()(bool v) { return makeBin_(&v, sizeof(v)); } };
template<> struct toBin_<uint8_t> { type_(Array_<uint8_t>) operator()(uint8_t v) { return makeBin_(&v, sizeof(v)); } };
template<> struct toBin_<uint16_t> { type_(Array_<uint8_t>) operator()(uint16_t v) { return makeBin_(&v, sizeof(v)); } };
template<> struct toBin_<uint32_t> { type_(Array_<uint8_t>) operator()(uint32_t v) { return makeBin_(&v, sizeof(v)); } };
template<> struct toBin_<uint64_t> { type_(Array_<uint8_t>) operator()(uint64_t v) { return makeBin_(&v, sizeof(v)); } };
template<typename T> type_(Array_<uint8_t>) toBinFunc_(T v) {
	int64_t p = -1;
	return makeBin_(&p, sizeof(p));
}

template<typename T> struct fromBin_ {};
template<typename T> struct fromBin_<type_(Array_<T>)> {
	type_(Array_<T>) operator()(type_(Array_<uint8_t>) b, int64_t& o) {
		int64_t l = *reinterpret_cast<int64_t*>(b->B + o);
		o += sizeof(int64_t);
		if (l == -1) return nullptr;
		type_(Array_<T>) r = new_(Array_<T>)();
		r->L = l;
		r->B = newPrimArray_(static_cast<std::size_t>(l) + bufLen_<T>(), T);
		for (int64_t i = 0; i < l; i++)
			r->B[i] = fromBin_<T>()(b, o);
		if (bufLen_<T>() > 0)
			r->B[l] = 0;
		return r;
	}
};
template<typename T> struct fromBin_<type_(List_<T>)> {
	type_(List_<T>) operator()(type_(Array_<uint8_t>) b, int64_t& o) {
		int64_t l = *reinterpret_cast<int64_t*>(b->B + o);
		o += sizeof(int64_t);
		if (l == -1) return nullptr;
		type_(List_<T>) r = new_(List_<T>)();
		int64_t d = *reinterpret_cast<int64_t*>(b->B + o);
		o += sizeof(int64_t);
		for (int64_t i = 0; i < l; i++)
		{
			r->B.push_back(fromBin_<T>()(b, o));
			if (i == d)
			{
				auto e = r->B.end();
				--e;
				r->I = e;
			}
		}
		return r;
	}
};
template<typename T> struct fromBin_<type_(Stack_<T>)> {
	type_(Stack_<T>) operator()(type_(Array_<uint8_t>) b, int64_t& o) {
		int64_t l = *reinterpret_cast<int64_t*>(b->B + o);
		o += sizeof(int64_t);
		if (l == -1) return nullptr;
		type_(Stack_<T>) r = new_(Stack_<T>)();
		for (int64_t i = 0; i < l; i++)
			r->B.push(fromBin_<T>()(b, o));
		return r;
	}
};
template<typename T> struct fromBin_<type_(Queue_<T>)> {
	type_(Queue_<T>) operator()(type_(Array_<uint8_t>) b, int64_t& o) {
		int64_t l = *reinterpret_cast<int64_t*>(b->B + o);
		o += sizeof(int64_t);
		if (l == -1) return nullptr;
		type_(Queue_<T>) r = new_(Queue_<T>)();
		for (int64_t i = 0; i < l; i++)
			r->B.push(fromBin_<T>()(b, o));
		return r;
	}
};
template<typename T1, typename T2> struct fromBin_<type_(Dict_<T1, T2>)> {
	type_(Dict_<T1, T2>) operator()(type_(Array_<uint8_t>) b, int64_t& o) {
		int64_t l = *reinterpret_cast<int64_t*>(b->B + o);
		o += sizeof(int64_t);
		if (l == -1) return nullptr;
		type_(Dict_<T1, T2>) r = new_(Dict_<T1, T2>)();
		r->L = l;
		for (int64_t i = 0; i < l; i++)
		{
			T1 k = fromBin_<T1>()(b, o);
			T2 v = fromBin_<T2>()(b, o);
			r->Add(k, v);
		}
		return r;
	}
};
template<typename T> struct fromBin_<type_(T)> {
	type_(T) operator()(type_(Array_<uint8_t>) b, int64_t& o) {
		int64_t y = *reinterpret_cast<int64_t*>(b->B + o);
		o += sizeof(int64_t);
		if (y == -1) return nullptr;
		return dcast_(T)(reinterpret_cast<type_(Class_)(*)(type_(Class_), type_(Array_<uint8_t>), int64_t*)>(classTable_[y + 6])(nullptr, b, &o));
	}
};
template<> struct fromBin_<int64_t> { int64_t operator()(type_(Array_<uint8_t>) b, int64_t& o) { int64_t r = *reinterpret_cast<int64_t*>(b->B + o); o += sizeof(int64_t); return r; } };
template<> struct fromBin_<double> { double operator()(type_(Array_<uint8_t>) b, int64_t& o) { double r = *reinterpret_cast<double*>(b->B + o); o += sizeof(double); return r; } };
template<> struct fromBin_<char16_t> { char16_t operator()(type_(Array_<uint8_t>) b, int64_t& o) { char16_t r = *reinterpret_cast<char16_t*>(b->B + o); o += sizeof(char16_t); return r; } };
template<> struct fromBin_<bool> { bool operator()(type_(Array_<uint8_t>) b, int64_t& o) { bool r = *reinterpret_cast<bool*>(b->B + o); o += sizeof(bool); return r; } };
template<> struct fromBin_<uint8_t> { uint8_t operator()(type_(Array_<uint8_t>) b, int64_t& o) { uint8_t r = *reinterpret_cast<uint8_t*>(b->B + o); o += sizeof(uint8_t); return r; } };
template<> struct fromBin_<uint16_t> { uint16_t operator()(type_(Array_<uint8_t>) b, int64_t& o) { uint16_t r = *reinterpret_cast<uint16_t*>(b->B + o); o += sizeof(uint16_t); return r; } };
template<> struct fromBin_<uint32_t> { uint32_t operator()(type_(Array_<uint8_t>) b, int64_t& o) { uint32_t r = *reinterpret_cast<uint32_t*>(b->B + o); o += sizeof(uint32_t); return r; } };
template<> struct fromBin_<uint64_t> { uint64_t operator()(type_(Array_<uint8_t>) b, int64_t& o) { uint64_t r = *reinterpret_cast<uint64_t*>(b->B + o); o += sizeof(uint64_t); return r; } };
template<typename T> T fromBinFunc_(type_(Array_<uint8_t>) b, int64_t& o) {
	o += sizeof(void*);
	return nullptr;
}

template<typename T> type_(Array_<T>) sub_(type_(Array_<T>) a, int64_t start, int64_t len) {
	if (len == -1)
		len = a->L - start;
	if (start < 0 || len < 0 || start + len > a->L)
		throw 0xe9170006;
	type_(Array_<T>) r = new_(Array_<T>)();
	r->L = len;
	r->B = newPrimArray_(static_cast<std::size_t>(len + bufLen_<T>()), T);
	for (int64_t i = 0; i < len; i++)
		r->B[i] = a->B[start + i];
	if (bufLen_<T>() > 0)
		r->B[len] = 0;
	return r;
}

template<typename T> type_(T) as_(const int64_t * y, type_(Class_) c, int64_t o) {
	if (c == nullptr)
		return nullptr;
	int64_t m = c->Y;
	for (; ; )
	{
		if (m == o)
			return dcast_(T)(c);
		if (m == 0)
			return nullptr;
		m = y[m];
	}
}

static bool is_(const int64_t * y, type_(Class_) c, int64_t o) {
	int64_t m = c->Y;
	for (; ; )
	{
		if (m == o)
			return true;
		if (m == 0)
			return false;
		m = y[m];
	}
}

template<typename T> T min_(type_(Array_<T>) a) {
	if (a->L == 0)
		return (T)0;
	T r = a->B[0];
	for (int64_t i = 0; i < a->L; i++)
	{
		if (cmp_(r, a->B[i]) > 0)
			r = a->B[i];
	}
	return r;
}

template<typename T> T max_(type_(Array_<T>) a) {
	if (a->L == 0)
		return (T)0;
	T r = a->B[0];
	for (int64_t i = 0; i < a->L; i++)
	{
		if (cmp_(r, a->B[i]) < 0)
			r = a->B[i];
	}
	return r;
}

template<typename T> type_(Array_<T>) repeat_(type_(Array_<T>) a, int64_t n) {
	type_(Array_<T>) r = new_(Array_<T>)();
	r->L = a->L * n;
	r->B = newPrimArray_(static_cast<std::size_t>(r->L) + bufLen_<T>(), T);
	for (int64_t i = 0; i < n; i++)
	{
		for (int64_t j = 0; j < a->L; j++)
			r->B[i * a->L + j] = a->B[j];
	}
	if (bufLen_<T>() > 0)
		r->B[r->L] = 0;
	return r;
}

template<typename T1, typename T2> dictImpl_<T1, T2>* dictRotateLeft_(dictImpl_<T1, T2> * n)
{
	dictImpl_<T1, T2>* r = n->CR;
	n->CR = r->CL;
	r->CL = n;
	r->R = n->R;
	n->R = true;
	return r;
}
template<typename T1, typename T2> dictImpl_<T1, T2>* dictRotateRight_(dictImpl_<T1, T2> * n)
{
	dictImpl_<T1, T2>* l = n->CL;
	n->CL = l->CR;
	l->CR = n;
	l->R = n->R;
	n->R = true;
	return l;
}
template<typename T1, typename T2> void dictFlip_(dictImpl_<T1, T2> * n)
{
	n->R = !n->R;
	n->CL->R = !n->CL->R;
	n->CR->R = !n->CR->R;
}
template<typename T1, typename T2> dictImpl_<T1, T2>* dictFixUp_(dictImpl_<T1, T2> * n)
{
	if (n->CR != nullptr && n->CR->R)
		n = dictRotateLeft_<T1, T2>(n);
	if (n->CL != nullptr && n->CL->R && n->CL->CL != nullptr && n->CL->CL->R)
		n = dictRotateRight_<T1, T2>(n);
	if (n->CL != nullptr && n->CL->R && n->CR != nullptr && n->CR->R)
		dictFlip_<T1, T2>(n);
	return n;
}
template<typename T1, typename T2> dictImpl_<T1, T2>* dictAddRec_(dictImpl_<T1, T2> * n, T1 k, T2 v, bool* a) {
	if (n == nullptr)
	{
		*a = true;
		return newPrim_(dictImpl_<T1, T2>)(k, v);
	}
	int64_t c = cmp_(k, n->K);
	if (c == 0)
	{
		n->V = v;
		return n;
	}
	if (c < 0)
		n->CL = dictAddRec_<T1, T2>(n->CL, k, v, a);
	else
		n->CR = dictAddRec_<T1, T2>(n->CR, k, v, a);
	return dictFixUp_<T1, T2>(n);
}
template<typename T1, typename T2> dictImpl_<T1, T2>* dictMoveRedLeft_(dictImpl_<T1, T2> * n)
{
	dictFlip_<T1, T2>(n);
	if (n->CR->CL != nullptr && n->CR->CL->R)
	{
		n->CR = dictRotateRight_<T1, T2>(n->CR);
		n = dictRotateLeft_<T1, T2>(n);
		dictFlip_<T1, T2>(n);
	}
	return n;
}
template<typename T1, typename T2> dictImpl_<T1, T2>* dictMoveRedRight_(dictImpl_<T1, T2> * n)
{
	dictFlip_<T1, T2>(n);
	if (n->CL->CL != nullptr && n->CL->CL->R)
	{
		n = dictRotateRight_<T1, T2>(n);
		dictFlip_<T1, T2>(n);
	}
	return n;
}
template<typename T1, typename T2> dictImpl_<T1, T2>* dictDelMinRec_(dictImpl_<T1, T2> * n)
{
	if (n->CL == nullptr)
		return nullptr;
	if (!n->CL->R && !(n->CL->CL != nullptr && n->CL->CL->R))
		n = dictMoveRedLeft_<T1, T2>(n);
	n->CL = dictDelMinRec_<T1, T2>(n->CL);
	return dictFixUp_<T1, T2>(n);

}
template<typename T1, typename T2> dictImpl_<T1, T2>* dictDelRec_(dictImpl_<T1, T2> * n, T1 k, bool* d) {
	if (n == nullptr)
		return nullptr;
	if (cmp_(k, n->K) < 0)
	{
		if (n->CL != nullptr && !n->CL->R && !(n->CL->CL != nullptr && n->CL->CL->R))
			n = dictMoveRedLeft_<T1, T2>(n);
		n->CL = dictDelRec_<T1, T2>(n->CL, k, d);
	}
	else
	{
		if (n->CL != nullptr && n->CL->R)
			n = dictRotateRight_<T1, T2>(n);
		if (n->CR != nullptr && !n->CR->R && !(n->CR->CL != nullptr && n->CR->CL->R))
			n = dictMoveRedRight_<T1, T2>(n);
		if (cmp_(k, n->K) == 0)
		{
			*d = true;
			if (n->CR == nullptr)
				return nullptr;
			dictImpl_<T1, T2>* p = n->CR;
			while (p->CL != nullptr)
				p = p->CL;
			n->K = p->K;
			n->V = p->V;
			n->CR = dictDelMinRec_<T1, T2>(n->CR);
		}
		else
			n->CR = dictDelRec_<T1, T2>(n->CR, k, d);
	}
	return dictFixUp_<T1, T2>(n);
}
template<typename T1, typename T2> dictImpl_<T1, T2>* dictCopyRec_(dictImpl_<T1, T2> * n) {
	if (n == nullptr)
		return nullptr;
	dictImpl_<T1, T2>* r = newPrim_(dictImpl_<T1, T2>)(copy_<T1>()(n->K), copy_<T2>()(n->V));
	r->R = n->R;
	r->CL = dictCopyRec_(n->CL);
	r->CR = dictCopyRec_(n->CR);
	return r;
}
template<typename T1, typename T2> void dictToBinRec_(type_(Array_<uint8_t>) a, dictImpl_<T1, T2> * d) {
	if (d->CL != nullptr)
		dictToBinRec_(a, d->CL);
	mergeBin_(a, toBin_<T1>()(d->K));
	mergeBin_(a, toBin_<T2>()(d->V));
	if (d->CR != nullptr)
		dictToBinRec_(a, d->CR);
}
template<typename T1, typename T2> T2 dictSearch_(dictImpl_<T1, T2> * r, T1 k, bool* f) {
	dictImpl_<T1, T2>* n = r;
	while (n != nullptr)
	{
		int64_t c = cmp_(k, n->K);
		if (c == 0)
		{
			*f = true;
			return n->V;
		}
		if (c < 0)
			n = n->CL;
		else
			n = n->CR;
	}
	*f = false;
	return (T2)0;
}
template<typename T1, typename T2> bool dictForEach_(dictImpl_<T1, T2> * r, bool(*f)(T1, T2, type_(Class_)), type_(Class_) p) {
	if (r == nullptr)
		return true;
	if (!dictForEach_<T1, T2>(r->CL, f, p))
		return false;
	if (!f(r->K, r->V, p))
		return false;
	if (!dictForEach_<T1, T2>(r->CR, f, p))
		return false;
	return true;
}
template<typename T1, typename T2> bool dictExist_(dictImpl_<T1, T2> * r, T1 k) {
	dictImpl_<T1, T2>* n = r;
	while (n != nullptr)
	{
		int64_t c = cmp_(k, n->K);
		if (c == 0)
			return true;
		if (c < 0)
			n = n->CL;
		else
			n = n->CR;
	}
	return false;
}
template<typename T1, typename T2> void dictFreeRec_(dictImpl_<T1, T2> * n) {
	if (n == nullptr)
		return;
	dictFreeRec_<T1, T2>(n->CL);
	dictFreeRec_<T1, T2>(n->CR);
	delPrim_(n);
}

static int64_t powI_(int64_t a, int64_t b) {
	switch (b)
	{
		case 0LL:
			return 1LL;
		case 1LL:
			return a;
		case 2LL:
			return a * a;
	}
	if (a == 1LL)
		return 1LL;
	if (a == -1LL)
		return (b & 1LL) == 0LL ? 1LL : -1LL;
	if (b < 0LL)
		return 0LL;
	int64_t r = 1LL;
	for (; ; )
	{
		if ((b & 1LL) == 1LL)
			r *= a;
		b >>= 1LL;
		if (b == 0LL)
			break;
		a *= a;
	}
	return r;
}

template<typename T> void reverse_(type_(Array_<T>) me) { std::reverse<T*>(me->B, me->B + me->L); }
template<typename T> bool sortCmp_(const T & a, const T & b) { return cmp_(a, b) < 0; }
template<typename T> void sort_(type_(Array_<T>) me) { std::sort<T*, bool(*)(const T&, const T&)>(me->B, me->B + me->L, sortCmp_<T>); }
static uint8_t sar_(uint8_t me_, int64_t n) { return static_cast<uint8_t>(static_cast<int8_t>(me_) >> n); }
static uint16_t sar_(uint16_t me_, int64_t n) { return static_cast<uint16_t>(static_cast<int16_t>(me_) >> n); }
static uint32_t sar_(uint32_t me_, int64_t n) { return static_cast<uint32_t>(static_cast<int32_t>(me_) >> n); }
static uint64_t sar_(uint64_t me_, int64_t n) { return static_cast<uint64_t>(static_cast<int64_t>(me_) >> n); }
static uint8_t endian_(uint8_t me_) { return me_; }
static uint16_t endian_(uint16_t me_) { return ((me_ & 0x00ff) << 8) | ((me_ & 0xff00) >> 8); }
static uint32_t endian_(uint32_t me_)
{
	me_ = ((me_ & 0x00ff00ff) << 8) | ((me_ & 0xff00ff00) >> 8);
	return ((me_ & 0x0000ffff) << 16) | ((me_ & 0xffff0000) >> 16);
}
static uint64_t endian_(uint64_t me_)
{
	me_ = ((me_ & 0x00ff00ff00ff00ff) << 8) | ((me_ & 0xff00ff00ff00ff00) >> 8);
	me_ = ((me_ & 0x0000ffff0000ffff) << 16) | ((me_ & 0xffff0000ffff0000) >> 16);
	return ((me_ & 0x00000000ffffffff) << 32) | ((me_ & 0xffffffff00000000) >> 32);
}

struct reader_ {
	reader_() : F(nullptr) {}
	std::FILE* F;
};

struct writer_ {
	writer_() : F(nullptr) {}
	std::FILE* F;
};

template<typename T>
struct listPtr_ {
	listPtr_<T>() {}
	typename T::iterator I;
};

static void init_() {
	setlocale(LC_ALL, "");
}
class k_o;
class k_n;
class k_aq;
class k_fy;
void k_main_();
static void k_d();
static void k_e();
static void k_f();
static void k_g();
using k_bk=type_(k_aq)(*)(type_(k_aq), int64_t, int64_t);
static void k_i();
static void k_j();
static void k_l(int64_t k_bw /*excpt*/);
static void k_p(type_(k_o) k_bz /*me*/);
static void k_q(k_o* k_ca);
static int64_t k_r(type_(k_o) k_cb /*me*/, type_(k_o) k_cc /*t*/);
static type_(k_o) k_s(type_(k_o) k_cd /*me*/);
static type_(Array_<uint8_t>) k_t(type_(k_o) k_cg /*me*/);
static type_(k_o) k_u(type_(k_o) k_ci /*me*/, type_(Array_<uint8_t>) k_cj /*bin*/, int64_t* k_ck /*idx*/);
static type_(Array_<char16_t>) k_v(type_(k_o) k_cn /*me*/);
static void k_w(type_(k_n) k_co /*me*/);
using k_cq=void(*)(type_(k_o));
static int64_t k_x(type_(k_n) k_cr /*me*/, int64_t k_cs /*min*/, int64_t k_ct /*max*/);
using k_db=uint64_t(*)(type_(k_n));
static uint64_t k_y(type_(k_n) k_de /*me*/);
using k_dg=uint32_t(*)(type_(k_n));
static double k_z(type_(k_n) k_dj /*me*/, double k_dk /*min*/, double k_dl /*max*/);
static void k_aa(type_(k_n) k_do /*me*/, uint32_t k_dp /*seed*/);
static uint32_t k_ab(type_(k_n) k_dv /*me*/);
static void k_ac(k_n* k_dx);
static type_(k_n) k_ad(type_(k_n) k_dy);
static type_(Array_<uint8_t>) k_ae(type_(k_n) k_eb);
static type_(k_n) k_af(type_(k_n) k_eh, type_(Array_<uint8_t>) k_ei, int64_t* k_ej);
static type_(k_n) k_ag(type_(k_n) k_em /*me2*/, uint32_t k_en /*seed*/);
using k_eo=void(*)(type_(k_n), uint32_t);
template<typename T_>static T_ k_ai(T_ k_ep /*me_*/, type_(Array_<int64_t>) k_eq /*type*/, T_ k_er /*n*/);
static int64_t k_aj();
static int64_t k_ak();
static int64_t k_an();
static type_(k_aq) k_ar(type_(k_aq) k_ez /*me*/, int64_t k_fa /*v*/, int64_t k_fb /*dist*/);
static void k_as(k_aq* k_fe);
static type_(k_aq) k_at(type_(k_aq) k_ff);
static type_(Array_<uint8_t>) k_au(type_(k_aq) k_fh);
static type_(k_aq) k_av(type_(k_aq) k_fl, type_(Array_<uint8_t>) k_fm, int64_t* k_fn);
template<typename T_,typename C_>static void k_bj(T_ k_fp /*me_*/, type_(Array_<int64_t>) k_fq /*type*/, C_ k_fr /*item*/);
static type_(Array_<int64_t>) k_bm(type_(Array_<type_(List_<type_(k_aq)>)>) k_fs /*graph*/, int64_t k_ft /*start*/);
using k_gi=void(*)(type_(k_fy), int64_t);
using k_go=int64_t(*)(type_(k_fy));
using k_gp=void(*)(type_(k_fy));
static void k_bu(type_(Array_<char16_t>) k_hg /*str*/);
template<typename T_>static type_(Array_<char16_t>) k_bv(T_ k_hh /*me_*/, type_(Array_<int64_t>) k_hi /*type*/);
template<typename T_>static T_ k_dh(T_ k_hj /*me_*/, type_(Array_<int64_t>) k_hk /*type*/, T_ k_hl /*n*/);
template<typename T_>static T_ k_di(T_ k_hm /*me_*/, type_(Array_<int64_t>) k_hn /*type*/, int64_t k_ho /*n*/);
template<typename T_>static T_ k_du(T_ k_hr /*me_*/, type_(Array_<int64_t>) k_hs /*type*/, int64_t k_ht /*n*/);
static type_(Array_<char16_t>) k_et();
static int64_t k_ew(type_(Array_<char16_t>) k_iq /*me_*/, bool* k_ir /*success*/);
template<typename T_>static T_ k_fw(T_ k_is /*me_*/, type_(Array_<int64_t>) k_it /*type*/, int64_t k_iu /*len*/);
static void k_fz(type_(k_fy) k_ix /*me*/);
static void k_ga(type_(k_fy) k_ja /*me*/, int64_t k_jb /*elem*/);
static void k_gb(type_(k_fy) k_jm /*me*/);
static int64_t k_gc(type_(k_fy) k_jy /*me*/);
static void k_gd(k_fy* k_jz);
static type_(k_fy) k_ge(type_(k_fy) k_ka);
static type_(Array_<uint8_t>) k_gf(type_(k_fy) k_kd);
static type_(k_fy) k_gg(type_(k_fy) k_kh, type_(Array_<uint8_t>) k_ki, int64_t* k_kj);
template<typename T_>static void k_gt(T_ k_km /*me_*/, type_(Array_<int64_t>) k_kn /*type*/);
template<typename T_,typename R_>static R_ k_ha(T_ k_ko /*me_*/, type_(Array_<int64_t>) k_kp /*type*/);
template<typename T_>static void k_hf(T_ k_ks /*me_*/, type_(Array_<int64_t>) k_kt /*type*/);
static char16_t k_ic();
template<typename T_>static T_ k_ip(T_ k_li /*me_*/, type_(Array_<int64_t>) k_lj /*type*/, int64_t k_lk /*start*/, int64_t k_ll /*len*/);
static char16_t k_ky();
static int64_t argc_;
static char** argv_;
// Class
class k_o : public Class_{
public:
k_o();
virtual ~k_o();
};
// Rnd
class k_n : public k_o{
public:
k_n();
virtual ~k_n();
uint32_t k_dq; // x
uint32_t k_dr; // y
uint32_t k_ds; // z
uint32_t k_dt; // w
};
// Edge
class k_aq : public k_o{
public:
k_aq();
virtual ~k_aq();
int64_t k_fc; // v
int64_t k_fd; // dist
};
// PriorityQueue
class k_fy : public k_o{
public:
k_fy();
virtual ~k_fy();
type_(Array_<int64_t>) k_iz; // data
int64_t k_gm; // len
};
static type_(k_n) k_m;
static type_(Array_<char16_t>) k_al;
k_o::k_o(): Class_(){ Y = 0; }
k_o::~k_o(){
k_q(this);
}
k_n::k_n(): k_o(), k_dq(), k_dr(), k_ds(), k_dt(){ Y = 8; }
k_n::~k_n(){
k_ac(this);
}
k_aq::k_aq(): k_o(), k_fc(), k_fd(){ Y = 21; }
k_aq::~k_aq(){
k_as(this);
}
k_fy::k_fy(): k_o(), k_iz(), k_gm(){ Y = 30; }
k_fy::~k_fy(){
k_gd(this);
}
// k_main_
void k_main_(){
int64_t k_b; // $
try{
try{
(k_d)();
(k_e)();
(k_f)();
(k_g)();
(k_i)();
(k_j)();
}catch(int64_t k_b){
if(((0LL) <= k_b && k_b <= (4294967295LL))){
(k_l)((k_b));
}
else{
throw;
}
}
}
catch(...){
(k_i)();
(k_j)();
throw;
}
}
// _init
static void k_d(){
}
// _init
static void k_e(){
type_(k_n) k_ah;
(k_m) = ((k_ag)((k_ah = new_(k_n)(), k_w(k_ah), k_ah), (k_ai<uint32_t>((static_cast<uint32_t>((k_aj)())), (nullptr), (static_cast<uint32_t>((k_ak)()))))));
}
// _initVars
static void k_f(){
(k_al) = (newArrayBin_<char16_t>(3,"\x20\x00\x2C\x00\x0A\x00"));
}
// main
static void k_g(){
int64_t k_am; // n
int64_t k_ao; // m
type_(Array_<type_(List_<type_(k_aq)>)>) k_ap; // graph
int64_t k_az;
int64_t k_be;
int64_t k_bg; // a
int64_t k_bh; // b
int64_t k_bi; // c
type_(Array_<int64_t>) k_bl; // dist1
type_(Array_<int64_t>) k_bn; // distN
int64_t k_br;
int64_t k_bt; // ans
int64_t k_ba;
int64_t k_bf;
int64_t k_bs;
(k_am) = ((k_an)());
(k_ao) = ((k_an)());
(k_ap) = (newArrays_<type_(Array_<type_(List_<type_(k_aq)>)>)>((k_am)));
for(k_az = (0LL), k_ba = ((k_am) - (1LL)); k_az <= k_ba; k_az += (1LL)){
((k_ap)->At(k_az)) = (new_(List_<type_(k_aq)>)());
}
for(k_be = (0LL), k_bf = ((k_ao) - (1LL)); k_be <= k_bf; k_be += (1LL)){
(k_bg) = (((k_an)()) - (1LL));
(k_bh) = (((k_an)()) - (1LL));
(k_bi) = ((k_an)());
k_bj<type_(List_<type_(k_aq)>), type_(k_aq)>(((k_ap)->At(k_bg)), (nullptr), ((reinterpret_cast<k_bk>(classTable_[(new_(k_aq)())->Y + 8]))((new_(k_aq)()), (k_bh), (k_bi))));
k_bj<type_(List_<type_(k_aq)>), type_(k_aq)>(((k_ap)->At(k_bh)), (nullptr), ((reinterpret_cast<k_bk>(classTable_[(new_(k_aq)())->Y + 8]))((new_(k_aq)()), (k_bg), (k_bi))));
}
(k_bl) = ((k_bm)((k_ap), (0LL)));
(k_bn) = ((k_bm)((k_ap), ((k_am) - (1LL))));
for(k_br = (0LL), k_bs = ((k_am) - (1LL)); k_br <= k_bs; k_br += (1LL)){
(k_bt) = (((k_bl)->At(k_br)) + ((k_bn)->At(k_br)));
(k_bu)((((newArrayBin_<char16_t>(0,""))->Cat(k_bv<int64_t>((k_bt), (nullptr))))->Cat(newArrayBin_<char16_t>(1,"\x0A\x00"))));
}
}
// _finVars
static void k_i(){
(k_al) = (nullptr);
(k_m) = (nullptr);
}
// _fin
static void k_j(){
}
// _err
static void k_l(int64_t k_bw /*excpt*/){
}
// ctor
static void k_p(type_(k_o) k_bz /*me*/){
}
// _dtor
static void k_q(k_o* k_ca){
}
// cmp
static int64_t k_r(type_(k_o) k_cb /*me*/, type_(k_o) k_cc /*t*/){
throw 3910598660LL;
}
// _copy
static type_(k_o) k_s(type_(k_o) k_cd /*me*/){
type_(k_o) k_ce;
type_(k_o) k_cf;
(k_ce) = (k_cf = new_(k_o)(), k_p(k_cf), k_cf);
return as_<k_o>(classTable_, (k_ce), 0);
}
// _toBin
static type_(Array_<uint8_t>) k_t(type_(k_o) k_cg /*me*/){
type_(Array_<uint8_t>) k_ch;
(k_ch) = (newArrays_<type_(Array_<uint8_t>)>((0LL)));
return k_ch;
}
// _fromBin
static type_(k_o) k_u(type_(k_o) k_ci /*me*/, type_(Array_<uint8_t>) k_cj /*bin*/, int64_t* k_ck /*idx*/){
type_(k_o) k_cl;
type_(k_o) k_cm;
(k_cl) = (k_cm = new_(k_o)(), k_p(k_cm), k_cm);
return k_cl;
}
// toStr
static type_(Array_<char16_t>) k_v(type_(k_o) k_cn /*me*/){
return newArrayBin_<char16_t>(0,"");
}
// ctor
static void k_w(type_(k_n) k_co /*me*/){
k_cq k_cp; // super
(k_cp) = (k_p);
}
// rnd
static int64_t k_x(type_(k_n) k_cr /*me*/, int64_t k_cs /*min*/, int64_t k_ct /*max*/){
uint64_t k_cw; // n
uint64_t k_cx; // m
uint64_t k_cy; // r
(k_cw) = (static_cast<uint64_t>(((k_ct) - (k_cs)) + (1LL)));
(k_cx) = ((0x0000000000000000ULL) - (((0x0000000000000000ULL) - (k_cw)) % (k_cw)));
(k_cy) = (0x0000000000000000ULL);
if((k_cx) == (0x0000000000000000ULL)){
(k_cy) = ((reinterpret_cast<k_db>(classTable_[(k_cr)->Y + 9]))((k_cr)));
}
else{
do{
(k_cy) = ((reinterpret_cast<k_db>(classTable_[(k_cr)->Y + 9]))((k_cr)));
}while((k_cx) <= (k_cy));
}
return (static_cast<int64_t>((k_cy) % (k_cw))) + (k_cs);
}
// rndBit64
static uint64_t k_y(type_(k_n) k_de /*me*/){
uint32_t k_df; // t
(k_df) = ((reinterpret_cast<k_dg>(classTable_[(k_de)->Y + 12]))((k_de)));
return k_dh<uint64_t>((k_di<uint64_t>((static_cast<uint64_t>(k_df)), (nullptr), (32LL))), (nullptr), (static_cast<uint64_t>((reinterpret_cast<k_dg>(classTable_[(k_de)->Y + 12]))((k_de)))));
}
// rndFloat
static double k_z(type_(k_n) k_dj /*me*/, double k_dk /*min*/, double k_dl /*max*/){
return (((static_cast<double>((reinterpret_cast<k_db>(classTable_[(k_dj)->Y + 9]))((k_dj)))) / (1.844674407370955e+19)) * ((k_dl) - (k_dk))) + (k_dk);
}
// setSeed
static void k_aa(type_(k_n) k_do /*me*/, uint32_t k_dp /*seed*/){
((k_do)->k_dq) = (0x075BCD15U);
((k_do)->k_dr) = (0x159A55E5U);
((k_do)->k_ds) = ((0x1F123BB5U) * (k_dp));
((k_do)->k_dt) = ((0x05491333U) * (k_du<uint32_t>(((k_do)->k_ds), (nullptr), (1LL))));
}
// xs128
static uint32_t k_ab(type_(k_n) k_dv /*me*/){
uint32_t k_dw; // t
(k_dw) = (k_ai<uint32_t>(((k_dv)->k_dq), (nullptr), (k_di<uint32_t>(((k_dv)->k_dq), (nullptr), (11LL)))));
((k_dv)->k_dq) = ((k_dv)->k_dr);
((k_dv)->k_dr) = ((k_dv)->k_ds);
((k_dv)->k_ds) = ((k_dv)->k_dt);
((k_dv)->k_dt) = (k_ai<uint32_t>((k_ai<uint32_t>(((k_dv)->k_dt), (nullptr), (k_du<uint32_t>(((k_dv)->k_dt), (nullptr), (19LL))))), (nullptr), (k_ai<uint32_t>((k_dw), (nullptr), (k_du<uint32_t>((k_dw), (nullptr), (8LL)))))));
return (k_dv)->k_dt;
}
// _dtor
static void k_ac(k_n* k_dx){
}
// _copy
static type_(k_n) k_ad(type_(k_n) k_dy){
type_(k_n) k_dz;
type_(k_n) k_ea;
(k_dz) = (k_ea = new_(k_n)(), k_w(k_ea), k_ea);
((k_dz)->k_dq) = ((k_dy)->k_dq);
((k_dz)->k_dr) = ((k_dy)->k_dr);
((k_dz)->k_ds) = ((k_dy)->k_ds);
((k_dz)->k_dt) = ((k_dy)->k_dt);
return as_<k_n>(classTable_, (k_dz), 8);
}
// _toBin
static type_(Array_<uint8_t>) k_ae(type_(k_n) k_eb){
type_(Array_<uint8_t>) k_ec;
(k_ec) = (newArrays_<type_(Array_<uint8_t>)>((0LL)));
(k_ec) = ((k_ec)->Cat(toBin_<uint32_t>()(((k_eb)->k_dq))));
(k_ec) = ((k_ec)->Cat(toBin_<uint32_t>()(((k_eb)->k_dr))));
(k_ec) = ((k_ec)->Cat(toBin_<uint32_t>()(((k_eb)->k_ds))));
(k_ec) = ((k_ec)->Cat(toBin_<uint32_t>()(((k_eb)->k_dt))));
return k_ec;
}
// _fromBin
static type_(k_n) k_af(type_(k_n) k_eh, type_(Array_<uint8_t>) k_ei, int64_t* k_ej){
type_(k_n) k_ek;
type_(k_n) k_el;
(k_ek) = (k_el = new_(k_n)(), k_w(k_el), k_el);
((k_ek)->k_dq) = (fromBin_<uint32_t>()((k_ei), (*k_ej)));
((k_ek)->k_dr) = (fromBin_<uint32_t>()((k_ei), (*k_ej)));
((k_ek)->k_ds) = (fromBin_<uint32_t>()((k_ei), (*k_ej)));
((k_ek)->k_dt) = (fromBin_<uint32_t>()((k_ei), (*k_ej)));
return k_ek;
}
// makeRnd
static type_(k_n) k_ag(type_(k_n) k_em /*me2*/, uint32_t k_en /*seed*/){
(reinterpret_cast<k_eo>(classTable_[(k_em)->Y + 11]))((k_em), (k_en));
return k_em;
}
// _xor
template<typename T_>static T_ k_ai(T_ k_ep /*me_*/, type_(Array_<int64_t>) k_eq /*type*/, T_ k_er /*n*/){
return k_ep^k_er;
}
// sysTime
static int64_t k_aj(){
return static_cast<int64_t>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
}
// now
static int64_t k_ak(){
return std::time(nullptr);
}
// inputInt
static int64_t k_an(){
type_(Array_<char16_t>) k_es; // s
bool k_eu; // b
int64_t k_ev; // r
(k_es) = ((k_et)());
(k_eu) = (false);
(k_ev) = ((k_ew)((k_es), (&k_eu)));
if(!(k_eu)){
throw 3910598664LL;
}
return k_ev;
}
// init
static type_(k_aq) k_ar(type_(k_aq) k_ez /*me*/, int64_t k_fa /*v*/, int64_t k_fb /*dist*/){
((k_ez)->k_fc) = (k_fa);
((k_ez)->k_fd) = (k_fb);
return k_ez;
}
// _dtor
static void k_as(k_aq* k_fe){
}
// _copy
static type_(k_aq) k_at(type_(k_aq) k_ff){
type_(k_aq) k_fg;
(k_fg) = (new_(k_aq)());
((k_fg)->k_fc) = ((k_ff)->k_fc);
((k_fg)->k_fd) = ((k_ff)->k_fd);
return as_<k_aq>(classTable_, (k_fg), 21);
}
// _toBin
static type_(Array_<uint8_t>) k_au(type_(k_aq) k_fh){
type_(Array_<uint8_t>) k_fi;
(k_fi) = (newArrays_<type_(Array_<uint8_t>)>((0LL)));
(k_fi) = ((k_fi)->Cat(toBin_<int64_t>()(((k_fh)->k_fc))));
(k_fi) = ((k_fi)->Cat(toBin_<int64_t>()(((k_fh)->k_fd))));
return k_fi;
}
// _fromBin
static type_(k_aq) k_av(type_(k_aq) k_fl, type_(Array_<uint8_t>) k_fm, int64_t* k_fn){
type_(k_aq) k_fo;
(k_fo) = (new_(k_aq)());
((k_fo)->k_fc) = (fromBin_<int64_t>()((k_fm), (*k_fn)));
((k_fo)->k_fd) = (fromBin_<int64_t>()((k_fm), (*k_fn)));
return k_fo;
}
// _addList
template<typename T_,typename C_>static void k_bj(T_ k_fp /*me_*/, type_(Array_<int64_t>) k_fq /*type*/, C_ k_fr /*item*/){
k_fp->B.push_back(k_fr);
}
// dists
static type_(Array_<int64_t>) k_bm(type_(Array_<type_(List_<type_(k_aq)>)>) k_fs /*graph*/, int64_t k_ft /*start*/){
int64_t k_fu; // n
type_(Array_<int64_t>) k_fv; // res
type_(k_fy) k_fx; // pq
int64_t k_gn; // data
int64_t k_gq; // u
int64_t k_gx;
type_(k_aq) k_gz; // e
int64_t k_hb; // v
int64_t k_hc; // dist
type_(k_fy) k_gh;
int64_t k_gy;
(k_fu) = ((k_fs)->Len());
(k_fv) = (k_fw<type_(Array_<int64_t>)>((new_(Array_<int64_t>)((9223372036854775807LL))), (nullptr), ((k_fs)->Len())));
((k_fv)->At(k_ft)) = (0LL);
(k_fx) = (k_gh = new_(k_fy)(), k_fz(k_gh), k_gh);
(reinterpret_cast<k_gi>(classTable_[(k_fx)->Y + 8]))((k_fx), (-((0LL) + (k_ft))));
while(((k_fx)->k_gm) != (0LL)){
(k_gn) = (-((reinterpret_cast<k_go>(classTable_[(k_fx)->Y + 10]))((k_fx))));
(reinterpret_cast<k_gp>(classTable_[(k_fx)->Y + 9]))((k_fx));
(k_gq) = ((k_gn) % (k_fu));
if(((k_fv)->At(k_gq)) < ((k_gn) / (k_fu))){
continue;
}
k_gt<type_(List_<type_(k_aq)>)>(((k_fs)->At(k_gq)), (nullptr));
for(k_gx = (0LL), k_gy = ((((k_fs)->At(k_gq))->Len()) - (1LL)); k_gx <= k_gy; k_gx += (1LL)){
(k_gz) = (k_ha<type_(List_<type_(k_aq)>), type_(k_aq)>(((k_fs)->At(k_gq)), (nullptr)));
(k_hb) = ((k_gz)->k_fc);
(k_hc) = ((k_gz)->k_fd);
if((((k_fv)->At(k_gq)) + (k_hc)) < ((k_fv)->At(k_hb))){
((k_fv)->At(k_hb)) = (((k_fv)->At(k_gq)) + (k_hc));
(reinterpret_cast<k_gi>(classTable_[(k_fx)->Y + 8]))((k_fx), (-((((k_fv)->At(k_hb)) * (k_fu)) + (k_hb))));
}
k_hf<type_(List_<type_(k_aq)>)>(((k_fs)->At(k_gq)), (nullptr));
}
}
return k_fv;
}
// print
static void k_bu(type_(Array_<char16_t>) k_hg /*str*/){
if(k_hg==nullptr){
fputs("(null)",stdout);
return;
}
#if defined(_WIN32)
fputws(reinterpret_cast<const wchar_t*>(k_hg->B),stdout);
#else
std::u16string s_=k_hg->B;
const std::string&t_=utf16ToUtf8_(s_);
fputs(t_.c_str(),stdout);
#endif
}
// _toStr
template<typename T_>static type_(Array_<char16_t>) k_bv(T_ k_hh /*me_*/, type_(Array_<int64_t>) k_hi /*type*/){
return toStr_(k_hh);
}
// _or
template<typename T_>static T_ k_dh(T_ k_hj /*me_*/, type_(Array_<int64_t>) k_hk /*type*/, T_ k_hl /*n*/){
return k_hj|k_hl;
}
// _shl
template<typename T_>static T_ k_di(T_ k_hm /*me_*/, type_(Array_<int64_t>) k_hn /*type*/, int64_t k_ho /*n*/){
return k_hm<<k_ho;
}
// _shr
template<typename T_>static T_ k_du(T_ k_hr /*me_*/, type_(Array_<int64_t>) k_hs /*type*/, int64_t k_ht /*n*/){
return k_hr>>k_ht;
}
// inputStr
static type_(Array_<char16_t>) k_et(){
type_(Array_<char16_t>) k_hw; // buf
int64_t k_hx; // ptr
char16_t k_ib; // c
(k_hw) = (newArrays_<type_(Array_<char16_t>)>((1024LL)));
(k_hx) = (0LL);
while(true){
(k_ib) = ((k_ic)());
if((k_ib) == (u'\uFFFF')){
if((k_hx) == (0LL)){
throw 3910598664LL;
}
break;
}
if((k_ib) == (u'\u0000')){
if((k_hx) == (0LL)){
continue;
}
break;
}
if((k_hx) == ((k_hw)->Len())){
(k_hw) = ((k_hw)->Cat(newArrays_<type_(Array_<char16_t>)>(((k_hw)->Len()))));
}
((k_hw)->At(k_hx)) = (k_ib);
(k_hx) = ((k_hx) + (1LL));
}
return k_ip<type_(Array_<char16_t>)>((k_hw), (nullptr), (0LL), (k_hx));
}
// _toInt
static int64_t k_ew(type_(Array_<char16_t>) k_iq /*me_*/, bool* k_ir /*success*/){
std::u16string u_=k_iq->B;
const std::string&t_=utf16ToUtf8_(u_);
try{
std::size_t s_;
int64_t v_=t_.size()>2&&t_[0]=='0'&&t_[1]=='x'?std::stoll(t_,&s_,16):std::stoull(t_,&s_);
if(s_==t_.size()){
*k_ir=true;
return v_;
}else{
*k_ir=false;
return 0;
}
}catch(...){
*k_ir=false;
return 0;
}
}
// _repeat
template<typename T_>static T_ k_fw(T_ k_is /*me_*/, type_(Array_<int64_t>) k_it /*type*/, int64_t k_iu /*len*/){
return repeat_(k_is,k_iu);
}
// ctor
static void k_fz(type_(k_fy) k_ix /*me*/){
k_cq k_iy; // super
(k_iy) = (k_p);
((k_ix)->k_iz) = (newArrays_<type_(Array_<int64_t>)>((1024LL)));
((k_ix)->k_gm) = (0LL);
}
// add
static void k_ga(type_(k_fy) k_ja /*me*/, int64_t k_jb /*elem*/){
int64_t k_jc; // n
int64_t k_ji; // i
int64_t k_jl; // tmp
(k_jc) = ((k_ja)->k_gm);
if((((k_ja)->k_iz)->Len()) == ((k_ja)->k_gm)){
((k_ja)->k_iz) = (((k_ja)->k_iz)->Cat(newArrays_<type_(Array_<int64_t>)>(((k_ja)->k_gm))));
}
(((k_ja)->k_iz)->At((k_ja)->k_gm)) = (k_jb);
((k_ja)->k_gm) = (((k_ja)->k_gm) + (1LL));
while((k_jc) != (0LL)){
(k_ji) = (((k_jc) - (1LL)) / (2LL));
if((((k_ja)->k_iz)->At(k_jc)) > (((k_ja)->k_iz)->At(k_ji))){
(k_jl) = (((k_ja)->k_iz)->At(k_jc));
(((k_ja)->k_iz)->At(k_jc)) = (((k_ja)->k_iz)->At(k_ji));
(((k_ja)->k_iz)->At(k_ji)) = (k_jl);
}
(k_jc) = (k_ji);
}
}
// pop
static void k_gb(type_(k_fy) k_jm /*me*/){
int64_t k_jn; // n
int64_t k_jp; // i
int64_t k_jq; // j
int64_t k_jx; // tmp
(k_jn) = (((k_jm)->k_gm) - (1LL));
(((k_jm)->k_iz)->At(0LL)) = (((k_jm)->k_iz)->At(k_jn));
((k_jm)->k_gm) = (((k_jm)->k_gm) - (1LL));
(k_jp) = (0LL);
(k_jq) = (1LL);
while((k_jq) < (k_jn)){
if(((k_jq) != ((k_jn) - (1LL))) && ((((k_jm)->k_iz)->At(k_jq)) < (((k_jm)->k_iz)->At((k_jq) + (1LL))))){
(k_jq) = ((k_jq) + (1LL));
}
if((((k_jm)->k_iz)->At(k_jp)) < (((k_jm)->k_iz)->At(k_jq))){
(k_jx) = (((k_jm)->k_iz)->At(k_jq));
(((k_jm)->k_iz)->At(k_jq)) = (((k_jm)->k_iz)->At(k_jp));
(((k_jm)->k_iz)->At(k_jp)) = (k_jx);
}
(k_jp) = (k_jq);
(k_jq) = (((2LL) * (k_jp)) + (1LL));
}
}
// top
static int64_t k_gc(type_(k_fy) k_jy /*me*/){
return ((k_jy)->k_iz)->At(0LL);
}
// _dtor
static void k_gd(k_fy* k_jz){
((k_jz)->k_iz) = (nullptr);
}
// _copy
static type_(k_fy) k_ge(type_(k_fy) k_ka){
type_(k_fy) k_kb;
type_(k_fy) k_kc;
(k_kb) = (k_kc = new_(k_fy)(), k_fz(k_kc), k_kc);
((k_kb)->k_iz) = (copy_<type_(Array_<int64_t>)>()((k_ka)->k_iz));
((k_kb)->k_gm) = ((k_ka)->k_gm);
return as_<k_fy>(classTable_, (k_kb), 30);
}
// _toBin
static type_(Array_<uint8_t>) k_gf(type_(k_fy) k_kd){
type_(Array_<uint8_t>) k_ke;
(k_ke) = (newArrays_<type_(Array_<uint8_t>)>((0LL)));
(k_ke) = ((k_ke)->Cat(toBin_<type_(Array_<int64_t>)>()(((k_kd)->k_iz))));
(k_ke) = ((k_ke)->Cat(toBin_<int64_t>()(((k_kd)->k_gm))));
return k_ke;
}
// _fromBin
static type_(k_fy) k_gg(type_(k_fy) k_kh, type_(Array_<uint8_t>) k_ki, int64_t* k_kj){
type_(k_fy) k_kk;
type_(k_fy) k_kl;
(k_kk) = (k_kl = new_(k_fy)(), k_fz(k_kl), k_kl);
((k_kk)->k_iz) = (fromBin_<type_(Array_<int64_t>)>()((k_ki), (*k_kj)));
((k_kk)->k_gm) = (fromBin_<int64_t>()((k_ki), (*k_kj)));
return k_kk;
}
// _head
template<typename T_>static void k_gt(T_ k_km /*me_*/, type_(Array_<int64_t>) k_kn /*type*/){
k_km->I=k_km->B.begin();
}
// _getList
template<typename T_,typename R_>static R_ k_ha(T_ k_ko /*me_*/, type_(Array_<int64_t>) k_kp /*type*/){
return *k_ko->I;
}
// _next
template<typename T_>static void k_hf(T_ k_ks /*me_*/, type_(Array_<int64_t>) k_kt /*type*/){
if(k_ks->I==k_ks->B.end())return;
++k_ks->I;
}
// inputCharWithDelimiter
static char16_t k_ic(){
char16_t k_kx; // c
int64_t k_lc;
int64_t k_ld;
while(true){
(k_kx) = ((k_ky)());
for(k_lc = (0LL), k_ld = (((k_al)->Len()) - (1LL)); k_lc <= k_ld; k_lc += (1LL)){
if(((k_kx) == ((k_al)->At(k_lc))) || (((k_kx) == (u'\u000D')) && (((k_al)->At(k_lc)) == (u'\u000A')))){
return u'\u0000';
}
}
if((k_kx) == (u'\u000D')){
continue;
}
return k_kx;
}
}
// _sub
template<typename T_>static T_ k_ip(T_ k_li /*me_*/, type_(Array_<int64_t>) k_lj /*type*/, int64_t k_lk /*start*/, int64_t k_ll /*len*/){
return sub_(k_li,k_lk,k_ll);
}
// inputLetter
static char16_t k_ky(){
#if defined(_WIN32)
wchar_t c_=fgetwc(stdin);
return static_cast<char16_t>(c_==WEOF?0xffff:c_);
#else
int l_;
char c_;
do{c_=fgetc(stdin);}while((c_&0xc0)==0x80);
if((c_&0x80)==0x00)l_=0;
else if((c_&0xe0)==0xc0){l_=1;c_&=0x1f;}
else if((c_&0xf0)==0xe0){l_=2;c_&=0x0f;}
else if((c_&0xf8)==0xf0){l_=3;c_&=0x07;}
else if((c_&0xfc)==0xf8){l_=4;c_&=0x03;}
else if((c_&0xfe)==0xfc){l_=5;c_&=0x01;}
else return 0xffff;
uint32_t u_=static_cast<uint32_t>(c_);
for(int i_=0;i_<l_;i_++)u_=(u_<<6)|(static_cast<uint32_t>(fgetc(stdin))&0x3f);
return static_cast<char16_t>(u_);
#endif
}
int main(int c, char** v){
argc_ = static_cast<int64_t>(c) - 1;
argv_ = v + 1;
classTable_[0] = 0;
classTable_[1] = reinterpret_cast<int64_t>(k_p);
classTable_[2] = reinterpret_cast<int64_t>(k_q);
classTable_[3] = reinterpret_cast<int64_t>(k_r);
classTable_[4] = reinterpret_cast<int64_t>(k_s);
classTable_[5] = reinterpret_cast<int64_t>(k_t);
classTable_[6] = reinterpret_cast<int64_t>(k_u);
classTable_[7] = reinterpret_cast<int64_t>(k_v);
classTable_[8] = 0;
classTable_[9] = reinterpret_cast<int64_t>(k_w);
classTable_[10] = reinterpret_cast<int64_t>(k_ac);
classTable_[11] = reinterpret_cast<int64_t>(k_r);
classTable_[12] = reinterpret_cast<int64_t>(k_ad);
classTable_[13] = reinterpret_cast<int64_t>(k_ae);
classTable_[14] = reinterpret_cast<int64_t>(k_af);
classTable_[15] = reinterpret_cast<int64_t>(k_v);
classTable_[16] = reinterpret_cast<int64_t>(k_x);
classTable_[17] = reinterpret_cast<int64_t>(k_y);
classTable_[18] = reinterpret_cast<int64_t>(k_z);
classTable_[19] = reinterpret_cast<int64_t>(k_aa);
classTable_[20] = reinterpret_cast<int64_t>(k_ab);
classTable_[21] = 0;
classTable_[22] = reinterpret_cast<int64_t>(k_p);
classTable_[23] = reinterpret_cast<int64_t>(k_as);
classTable_[24] = reinterpret_cast<int64_t>(k_r);
classTable_[25] = reinterpret_cast<int64_t>(k_at);
classTable_[26] = reinterpret_cast<int64_t>(k_au);
classTable_[27] = reinterpret_cast<int64_t>(k_av);
classTable_[28] = reinterpret_cast<int64_t>(k_v);
classTable_[29] = reinterpret_cast<int64_t>(k_ar);
classTable_[30] = 0;
classTable_[31] = reinterpret_cast<int64_t>(k_fz);
classTable_[32] = reinterpret_cast<int64_t>(k_gd);
classTable_[33] = reinterpret_cast<int64_t>(k_r);
classTable_[34] = reinterpret_cast<int64_t>(k_ge);
classTable_[35] = reinterpret_cast<int64_t>(k_gf);
classTable_[36] = reinterpret_cast<int64_t>(k_gg);
classTable_[37] = reinterpret_cast<int64_t>(k_v);
classTable_[38] = reinterpret_cast<int64_t>(k_ga);
classTable_[39] = reinterpret_cast<int64_t>(k_gb);
classTable_[40] = reinterpret_cast<int64_t>(k_gc);
init_();
k_main_();
return static_cast<int>(exitCode_);
}
//}}}
