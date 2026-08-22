In C on Linux, permission bit flags passed as the third argument (`mode`) to `open()`—or `creat()`—are defined in `<sys/stat.h>`. They follow the format `S_I[R/W/X][USR/GRP/OTH]`.

### Permission Flags (`mode`)

| Category | Constant | Octal | Description |
| --- | --- | --- | --- |
| **User (Owner)** | `S_IRUSR` | `0400` | Read permission |
|  | `S_IWUSR` | `0200` | Write permission |
|  | `S_IXUSR` | `0100` | Execute permission |
|  | `S_IRWXU` | `0700` | Read, write, and execute combined |
| **Group** | `S_IRGRP` | `0040` | Read permission |
|  | `S_IWGRP` | `0020` | Write permission |
|  | `S_IXGRP` | `0010` | Execute permission |
|  | `S_IRWXG` | `0070` | Read, write, and execute combined |
| **Others (All)** | `S_IROTH` | `0004` | Read permission |
|  | `S_IWOTH` | `0002` | Write permission |
|  | `S_IXOTH` | `0001` | Execute permission |
|  | `S_IRWXO` | `0007` | Read, write, and execute combined |

---

### Special Mode Bits

| Constant | Octal | Description |
| --- | --- | --- |
| `S_ISUID` | `04000` | Set-user-ID bit |
| `S_ISGID` | `02000` | Set-group-ID bit |
| `S_ISVTX` | `01000` | Sticky bit |

---

### Basic Example

Combine flags using the bitwise OR operator (`|`). Note that the mode argument is required only when creating a file (such as with `O_CREAT` or `O_TMPFILE`).

```c
#include <fcntl.h>
#include <sys/stat.h>

int fd = open("example.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
// Equates to 0644 permission (rw-r--r--)

```

> **Note:** The final permissions applied to the file on disk are modified by the calling process's `umask` value (`mode & ~umask`).
