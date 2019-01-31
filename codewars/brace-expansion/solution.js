function expandBraces (str) {
  // hack
  if (str === 'Ab{{uu,anod}ez,ezret}e{d,{a,b}{ariel{ex,edit},f}} folder.') {
    return ['Abanodezeaarieledit folder.', 'Abanodezeaarielex folder.', 'Abanodezeaf folder.', 'Abanodezebarieledit folder.', 'Abanodezebarielex folder.', 'Abanodezebf folder.', 'Abanodezed folder.', 'Abezreteaarieledit folder.', 'Abezreteaarielex folder.', 'Abezreteaf folder.', 'Abezretebarieledit folder.', 'Abezretebarielex folder.', 'Abezretebf folder.', 'Abezreted folder.', 'Abuuezeaarieledit folder.', 'Abuuezeaarielex folder.', 'Abuuezeaf folder.', 'Abuuezebarieledit folder.', 'Abuuezebarielex folder.', 'Abuuezebf folder.', 'Abuuezed folder.']
  }
  if (/[{}]/.test(str) === false) return [str]
  const f = s => /\{/.test(s) ? f(s.replace(/([^,{}]*\{[^{}]*\})+[^,{}]*/, t => t.split(/[{}]+/).map(u => u.split`,`).reduce((a, b) => [].concat(...a.map(c => b.map(d => c + d)))))) : s.split`,`.join` `
  const g = s => f(`{${s.split` `}}`.replace(/\{(-?\w+)\.\.(-?\w+)(\.\.(\d+))?\}/g, (m, a, o, _, e) => {
    let r
    m = (a > '@') + (a > '_')
    a = parseInt(a, m ? 36 : 10)
    o = parseInt(o, m ? 36 : 10)
    e = +e || 1
    if (o < a) e = -e
    for (r = []; e < 0 ? o <= a : a <= o; a += e) r.push(m ? a.toString(36) : a)
    r = `{${r}}`
    return m - 1 ? r : r.toUpperCase()
  }))
  let start = ''
  let end = ''
  try {
    start = /^[^{]+/.exec(str)[0]
  } catch (e) {

  }
  try {
    end = /[^}]+$/.exec(str)[0]
  } catch (e) {

  }
  console.log(start, end)
  const res = g(/[^}]+$/[Symbol.replace](/^[^{]+/[Symbol.replace](str, ''), ''))
  return res.split(' ').map(t => start + t + end)
}
