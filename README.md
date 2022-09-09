# bob1996w's corne keymap

## Build firmware
1. Setup QMK correctly
2. Symlink the directory
```
ln -s /<absolute path to this folder>/keymaps/bob1996w <QMK folder>/keyboards/crkbd/keymaps/bob1996w
```
3. Build firmware, at QMK folder:
```
qmk compile -kb crkbd/rev1/common -km bob1996w
```

