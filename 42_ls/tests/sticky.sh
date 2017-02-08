
dirs="./LOL"
ft_args=-lN1a
unx_args=-la
ft_file=ft.diff
unx_file=ux.diff

rm -rf LOL;
mkdir LOL; chmod +s LOL; chmod +t LOL;
.././ft_ls $ft_args $dirs ; ls $unx_args $dirs  ; 
