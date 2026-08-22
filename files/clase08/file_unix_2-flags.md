The access and status flags passed as the second argument (`flags`) to `open()` are defined in `<fcntl.h>`. They are categorized into access modes, creation flags, and status flags.

### Access Modes

*Exactly one of these must be specified.*

| Constant | Octal / Hex | Description |
| --- | --- | --- |
| `O_RDONLY` | `00` | Open for read-only access |
| `O_WRONLY` | `01` | Open for write-only access |
| `O_RDWR` | `02` | Open for reading and writing |

---

### Creation Flags

*Controls how the file is opened or created. Bitwise OR (`|`) with access mode.*

| Constant | Description |
| --- | --- |
| `O_CREAT` | Create the file if it does not exist (requires third argument `mode`) |
| `O_EXCL` | Ensure file creation; fails if the file already exists (used with `O_CREAT`) |
| `O_NOCTTY` | If the file is a terminal device, prevent it from becoming the controlling terminal |
| `O_TRUNC` | Truncate file length to 0 if it already exists and is open for writing |
| `O_DIRECTORY` | Fail if the path is not a directory |
| `O_NOFOLLOW` | Fail if the trailing component of the path is a symbolic link |
| `O_CLOEXEC` | Set the close-on-exec flag (`FD_CLOEXEC`) on the new file descriptor |
| `O_TMPFILE` | Create an unnamed temporary file in the specified directory |

---

### Operating Status Flags

*Modifies I/O operations on the file descriptor.*

| Constant | Description |
| --- | --- |
| `O_APPEND` | Open in append mode; all writes occur at the end of the file |
| `O_NONBLOCK` / `O_NDELAY` | Open in non-blocking mode for open and subsequent I/O operations |
| `O_SYNC` | Write operations block until data and metadata are physically written to disk |
| `O_DSYNC` | Write operations block until data is written, but ignore non-critical metadata |
| `O_ASYNC` | Generate a signal (`SIGIO`) when I/O becomes possible |
| `O_DIRECT` | Bypass the kernel page cache for direct disk I/O |
| `O_NOATIME` | Do not update the file's last access time (`atime`) on read operations |
