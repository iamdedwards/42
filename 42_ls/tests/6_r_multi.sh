
ft_args=-rN1
unx_args=-r
ft_file=ft.diff
unx_file=ux.diff

param="/etc /Applications ~"
.././ft_ls $ft_args $param > $ft_file ; ls $unx_args $param > $unx_file ; vimdiff $ft_file $unx_file
