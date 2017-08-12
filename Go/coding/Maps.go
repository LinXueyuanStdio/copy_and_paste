/*
Implement WordCount. It should return a map of the counts of each “word” in the string s. The wc.Test function runs a test suite against the provided function and prints success or failure.
*/

package main

import (
	"golang.org/x/tour/wc"
)

func WordCount(s string) map[string]int {
	var m map[string]int
	m = make(map[string]int)
	
	sign := 0
	i:=0
    for ; i<len(s[:]); i++ {
	    if s[i:i+1] == " " {
		    m[s[sign:i]] = 0
		    sign = i+1
		}
	}
	m[s[sign:i]] = 0
	
	sign=0
	i=0
    for ; i<len(s[:]); i++ {
	    if s[i:i+1] == " " {
		    m[s[sign:i]]++
		    sign = i+1
		}
	}
	m[s[sign:i]]++
	
	return m
}

func main() {
	wc.Test(WordCount)
}

