#!/usr/bin/python
# --------------------------------------------------------
# -- Bullet librairy
# --------------------------------------------------------
import lutin.module as module
import lutin.tools as tools
import os

def get_type():
	return "LIBRARY"

def get_desc():
	return "C++ graphic drawer"

def get_licence():
	return "BSD-3"

def get_compagny_type():
	return "com"

def get_compagny_name():
	return "antigrain"

def get_maintainer():
	return ["Maxim Shemanarev <mcseem@antigrain.com>"]

def get_version():
	return [2,4]

def create(target, module_name):
	my_module = module.Module(__file__, module_name, get_type())
	my_module.add_module_depend(['etk', 'freetype'])
	my_module.add_path(os.path.join(tools.get_current_path(__file__), "agg"))
	my_module.add_path(os.path.join(tools.get_current_path(__file__), "agg/util"))
	my_module.add_path(tools.get_current_path(__file__))
	my_module.add_src_file([
		'agg/agg_arc.cpp',
		'agg/agg_arrowhead.cpp',
		'agg/agg_bezier_arc.cpp',
		'agg/agg_bspline.cpp',
		'agg/agg_curves.cpp',
		'agg/agg_embedded_raster_fonts.cpp',
		'agg/agg_font_freetype.cpp',
		'agg/agg_gsv_text.cpp',
		'agg/agg_image_filters.cpp',
		'agg/agg_line_aa_basics.cpp',
		'agg/agg_line_profile_aa.cpp',
		'agg/agg_rounded_rect.cpp',
		'agg/agg_sqrt_tables.cpp',
		'agg/agg_trans_affine.cpp',
		'agg/agg_trans_double_path.cpp',
		'agg/agg_trans_single_path.cpp',
		'agg/agg_trans_warp_magnifier.cpp',
		'agg/agg_vcgen_bspline.cpp',
		'agg/agg_vcgen_contour.cpp',
		'agg/agg_vcgen_dash.cpp',
		'agg/agg_vcgen_markers_term.cpp',
		'agg/agg_vcgen_smooth_poly1.cpp',
		'agg/agg_vcgen_stroke.cpp',
		'agg/agg_vpgen_clip_polygon.cpp',
		'agg/agg_vpgen_clip_polyline.cpp',
		'agg/agg_vpgen_segmentator.cpp'
		])
	my_module.add_header_file([
		'agg/agg_color_rgba.h',
		'agg/agg_rasterizer_outline.h',
		'agg/agg_trans_single_path.h',
		'agg/agg_clip_liang_barsky.h',
		'agg/agg_span_gouraud_rgba.h',
		'agg/agg_renderer_base.h',
		'agg/agg_rendering_buffer_dynarow.h',
		'agg/agg_embedded_raster_fonts.h',
		'agg/agg_alpha_mask_u8.h',
		'agg/agg_scanline_boolean_algebra.h',
		'agg/agg_conv_transform.h',
		'agg/agg_span_gradient_alpha.h',
		'agg/agg_conv_marker_adaptor.h',
		'agg/agg_trans_warp_magnifier.h',
		'agg/agg_conv_gpc.h',
		'agg/agg_trans_affine.h',
		'agg/agg_conv_close_polygon.h',
		'agg/agg_pattern_filters_rgba.h',
		'agg/agg_conv_adaptor_vpgen.h',
		'agg/agg_span_image_filter_rgba.h',
		'agg/agg_font_cache_manager.h',
		'agg/agg_conv_dash.h',
		'agg/agg_path_storage.h',
		'agg/agg_scanline_u.h',
		'agg/agg_vpgen_segmentator.h',
		'agg/agg_vcgen_stroke.h',
		'agg/agg_bspline.h',
		'agg/agg_span_subdiv_adaptor.h',
		'agg/agg_rasterizer_outline_aa.h',
		'agg/agg_span_pattern_rgba.h',
		'agg/agg_conv_bspline.h',
		'agg/agg_bitset_iterator.h',
		'agg/agg_span_allocator.h',
		'agg/agg_span_interpolator_linear.h',
		'agg/agg_pixfmt_rgb.h',
		'agg/agg_renderer_primitives.h',
		'agg/agg_trans_perspective.h',
		'agg/agg_gradient_lut.h',
		'agg/agg_conv_unclose_polygon.h',
		'agg/agg_basics.h',
		'agg/agg_rasterizer_sl_clip.h',
		'agg/agg_conv_segmentator.h',
		'agg/agg_span_interpolator_persp.h',
		'agg/util/agg_color_conv_rgb8.h',
		'agg/util/agg_color_conv_rgb16.h',
		'agg/util/agg_color_conv.h',
		'agg/agg_image_accessors.h',
		'agg/agg_conv_adaptor_vcgen.h',
		'agg/agg_config.h',
		'agg/agg_scanline_p.h',
		'agg/agg_bezier_arc.h',
		'agg/agg_span_gradient.h',
		'agg/agg_renderer_outline_aa.h',
		'agg/agg_vcgen_bspline.h',
		'agg/agg_vpgen_clip_polyline.h',
		'agg/agg_conv_smooth_poly1.h',
		'agg/agg_rounded_rect.h',
		'agg/agg_arrowhead.h',
		'agg/agg_rendering_buffer.h',
		'agg/agg_rasterizer_compound_aa.h',
		'agg/agg_scanline_bin.h',
		'agg/agg_span_gouraud.h',
		'agg/agg_trans_viewport.h',
		'agg/agg_image_filters.h',
		'agg/agg_conv_clip_polygon.h',
		'agg/agg_conv_shorten_path.h',
		'agg/agg_path_length.h',
		'agg/agg_conv_concat.h',
		'agg/agg_bounding_rect.h',
		'agg/agg_conv_stroke.h',
		'agg/agg_span_image_filter_gray.h',
		'agg/agg_shorten_path.h',
		'agg/agg_path_storage_integer.h',
		'agg/agg_color_gray.h',
		'agg/agg_rasterizer_scanline_aa.h',
		'agg/agg_span_pattern_rgb.h',
		'agg/agg_conv_marker.h',
		'agg/agg_span_image_filter.h',
		'agg/agg_pixfmt_transposer.h',
		'agg/agg_array.h',
		'agg/agg_rasterizer_cells_aa.h',
		'agg/agg_span_pattern_gray.h',
		'agg/agg_span_image_filter_rgb.h',
		'agg/agg_renderer_raster_text.h',
		'agg/agg_renderer_outline_image.h',
		'agg/agg_conv_contour.h',
		'agg/agg_gamma_functions.h',
		'agg/agg_font_freetype.h',
		'agg/agg_math_stroke.h',
		'agg/agg_vpgen_clip_polygon.h',
		'agg/agg_vcgen_dash.h',
		'agg/agg_renderer_mclip.h',
		'agg/agg_vcgen_vertex_sequence.h',
		'agg/agg_pixfmt_rgb_packed.h',
		'agg/agg_line_aa_basics.h',
		'agg/agg_arc.h',
		'agg/agg_trans_bilinear.h',
		'agg/agg_vcgen_markers_term.h',
		'agg/agg_blur.h',
		'agg/agg_conv_clip_polyline.h',
		'agg/agg_ellipse_bresenham.h',
		'agg/agg_glyph_raster_bin.h',
		'agg/agg_pixfmt_gray.h',
		'agg/agg_span_interpolator_trans.h',
		'agg/agg_renderer_scanline.h',
		'agg/agg_gamma_lut.h',
		'agg/agg_scanline_storage_bin.h',
		'agg/agg_gsv_text.h',
		'agg/agg_span_converter.h',
		'agg/agg_simul_eq.h',
		'agg/agg_vertex_sequence.h',
		'agg/agg_conv_curve.h',
		'agg/agg_trans_double_path.h',
		'agg/agg_pixfmt_amask_adaptor.h',
		'agg/agg_curves.h',
		'agg/agg_span_solid.h',
		'agg/agg_ellipse.h',
		'agg/agg_span_interpolator_adaptor.h',
		'agg/agg_span_gouraud_gray.h',
		'agg/agg_pixfmt_rgba.h',
		'agg/agg_vcgen_smooth_poly1.h',
		'agg/agg_math.h',
		'agg/agg_scanline_storage_aa.h',
		'agg/agg_dda_line.h',
		'agg/agg_renderer_markers.h',
		'agg/agg_vcgen_contour.h'
		])
	#ewol abstraction of the graphic librairies :
	# TODO : Maybe deprecated ...
	my_module.add_src_file([
		'draw/debug.cpp',
		'draw/Color.cpp',
		'draw/Image.cpp'
		])
	my_module.add_header_file([
		'draw/Color.h',
		'draw/Image.h'
		])
	return my_module
