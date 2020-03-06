function lcs(str1, str2) {
    const n = str1.length
    const m = str2.length
    const a = []
    for (let i = 0; i <= n; i++) {
        a[i] = []
        for (let j = 0; j <= m; j++) {
            a[i][j] = 0
            if (i === n || j === m) {
                // skip
            } else if (str1[i] === str2[j]) {
                a[i][j]++
            }
        }
    }
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (str1[i] === str2[j] && i !== 0 && j !== 0) {
                a[i][j] += a[i - 1][j - 1]
            } else {
                a[i][j] = Math.max(
                    i !== 0 ? a[i - 1][j] : a[i][j],
                    j !== 0 ? a[i][j - 1] : a[i][j],
                )
            }
        }
    }

    function find(i, j) {
        if (i < 0 || j < 0) return ''
        if (str1[i] === str2[j]) return find(i - 1, j - 1) + str2[j]
        if ((a[i] != null ? a[i][j - 1] : 0) > (a[i - 1] != null ? a[i - 1][j] : 0))
            return find(i, j - 1)
        return find(i - 1, j)
    }

    return find(n - 1, m - 1) || ''
}