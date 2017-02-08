
dirs="fdar"
ft_args=-lN1
unx_args=-l
ft_file=ft.diff
unx_file=ux.diff
rm -f fdar
ln -s ~ fdar
.././ft_ls $ft_args $dirs; ls $unx_args $dirs;
