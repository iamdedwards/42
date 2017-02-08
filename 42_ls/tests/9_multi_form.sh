ft_args=-N1
unx_args=
ft_file=ft.diff
unx_file=ux.diff

param=/
ft_args=-ltN1
unx_args=-lt
.././ft_ls $ft_args $param > $ft_file ; ls $unx_args $param > $unx_file ; vimdiff $ft_file $unx_file
ft_args="-l -t -N -1"
.././ft_ls $ft_args $param > $ft_file ; ls $unx_args $param > $unx_file ; vimdiff $ft_file $unx_file
ft_args=-lrN1
unx_args=-lr
.././ft_ls $ft_args $param > $ft_file ; ls $unx_args $param > $unx_file ; vimdiff $ft_file $unx_file
ft_args="-l -r -N -1"
.././ft_ls $ft_args $param > $ft_file ; ls $unx_args $param > $unx_file ; vimdiff $ft_file $unx_file
