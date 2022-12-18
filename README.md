# Slurm log seq

Generate sequential Slurm log names

## Example
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
