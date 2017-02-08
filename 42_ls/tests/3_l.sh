ft_args=-lN1
unx_args=-l
ft_file=ft.diff
unx_file=ux.diff

param=
.././ft_ls $ft_args $param > $ft_file ; ls $unx_args $param > $unx_file ; vimdiff $ft_file $unx_file
param=/bin
.././ft_ls $ft_args $param > $ft_file ; ls $unx_args $param > $unx_file ; vimdiff $ft_file $unx_file
param=3_l.sh
.././ft_ls $ft_args $param > $ft_file ; ls $unx_args $param > $unx_file ; vimdiff $ft_file $unx_file
