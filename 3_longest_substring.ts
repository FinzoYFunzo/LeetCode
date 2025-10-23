// Last Submission
// 3ms || Beats 94.10%


function lengthOfLongestSubstring(s: string): number {
    let start_index = 0;
    let max_size = 0;
    const letters = new Map<string, number>();
    let last_seen: number | undefined = 0;

    let i = 0;
    // por alguna razon while esta más optimizado que for
    while (i < s.length ) {
      const this_index = letters.get(s[i]);
      if (this_index !== undefined && this_index >= start_index) last_seen = this_index
      else last_seen = undefined

      if (last_seen !== undefined) {
        max_size = Math.max(max_size, i - start_index) // ocupar Math.max en vez de un if

        start_index = last_seen + 1;
      }
      
      letters.set(s[i], i)
      i++;
    }
    max_size = Math.max(max_size, s.length - start_index)
    return max_size;
};
