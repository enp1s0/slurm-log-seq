# Slurm log seq

Generate sequential Slurm log names

## Usage
```
./slurm-log-seq [Optional: -n] [start: e.g. 10328/slurm-123987.out] [end]
```

- When `-n` is specified, it outputs only job numbers.
- The start and end have to be identified by `([^0-9]*)([0-9]+)([^0-9]*)`. It means that numbers are only included in the part of job ID.

### Example
```
$ slurm-log-seq slurm-100.out slurm-105.out
slurm-100.out slurm-101.out slurm-102.out slurm-103.out slurm-104.out slurm-105.out

$ cat $(slurm-log-seq slurm-100.out slurm-105.out) | grep "RESULT"
...

$ scancel $(slurm-log-seq -n slurm-100.out slurm-105.out)
...
```

## Build
```bash
make
```

## License
The MIT License
