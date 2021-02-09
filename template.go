package main

import (
	"bufio"
	"fmt"
	"os"
)

const nMax int = 1

var nTest, n int
var a [nMax]int

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	fmt.Fscan(in, &nTest)
	for t := 0; t < nTest; t++ {
		fmt.Fscan(in, &n)
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &a[i])
		}

		fmt.Fprintln(out, a)
	}

	out.Flush()
}
