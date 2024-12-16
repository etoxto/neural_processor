#include "cpu.h"
#include "local_mem.h"
#include "bus.h"
#include "iocontroller.h"
#include "control_unit.h"

#include "nodes.h"

int sc_main(int argc, char* argv[])
{
    CPU first_cpu_core("first_cpu");
    CPU second_cpu_core("second_cpu");
    CPU third_cpu_core("third_cpu");
    CPU fourth_cpu_core("fourth_cpu");
    CPU fifth_cpu_core("fifth_cpu");

    LocalMem first_lmem("first_lmem");
    LocalMem second_lmem("second_lmem");
    LocalMem third_lmem("third_lmem");
    LocalMem fourth_lmem("fourth_lmem");
    LocalMem fifth_lmem("fifth_lmem");

    Bus bus("bus");
    IOController ioc("ioc");
    ControlUnit cu("cu");

    sc_clock clk("clk", sc_time(10, SC_NS));
    sc_signal<int> mem_data_i;
    sc_signal<int> first_cpu_addr_bo;
    sc_signal<float> first_cpu_data_bo;
    sc_signal<int> second_cpu_addr_bo;
    sc_signal<float> second_cpu_data_bo;
    sc_signal<int> third_cpu_addr_bo;
    sc_signal<float> third_cpu_data_bo;
    sc_signal<int> fourth_cpu_addr_bo;
    sc_signal<float> fourth_cpu_data_bo;
    sc_signal<int> fifth_cpu_addr_bo;
    sc_signal<float> fifth_cpu_data_bo;

    sc_signal<bool> first_cpu_wr_bo;
    sc_signal<bool> first_cpu_rd_bo;
    sc_signal<bool> second_cpu_wr_bo;
    sc_signal<bool> second_cpu_rd_bo;
    sc_signal<bool> third_cpu_wr_bo;
    sc_signal<bool> third_cpu_rd_bo;
    sc_signal<bool> fourth_cpu_wr_bo;
    sc_signal<bool> fourth_cpu_rd_bo;
    sc_signal<bool> fifth_cpu_wr_bo;
    sc_signal<bool> fifth_cpu_rd_bo;

    sc_signal<bool> cu_first_cpu_start_o;
    sc_signal<bool> cu_second_cpu_start_o;
    sc_signal<bool> cu_third_cpu_start_o;
    sc_signal<bool> cu_fourth_cpu_start_o;
    sc_signal<bool> cu_fifth_cpu_start_o;

    sc_signal<bool> first_cpu_busy_o;
    sc_signal<bool> second_cpu_busy_o;
    sc_signal<bool> third_cpu_busy_o;
    sc_signal<bool> fourth_cpu_busy_o;
    sc_signal<bool> fifth_cpu_busy_o;

    sc_signal<int> cu_first_cpu_a_size_o;
    sc_signal<int> cu_second_cpu_a_size_o;
    sc_signal<int> cu_third_cpu_a_size_o;
    sc_signal<int> cu_fourth_cpu_a_size_o;
    sc_signal<int> cu_fifth_cpu_a_size_o;

    sc_signal<int> cu_first_cpu_curr_neuron_o;
    sc_signal<int> cu_second_cpu_curr_neuron_o;
    sc_signal<int> cu_third_cpu_curr_neuron_o;
    sc_signal<int> cu_fourth_cpu_curr_neuron_o;
    sc_signal<int> cu_fifth_cpu_curr_neuron_o;

    sc_signal<int> cu_first_cpu_w_offset_o;
    sc_signal<int> cu_second_cpu_w_offset_o;
    sc_signal<int> cu_third_cpu_w_offset_o;
    sc_signal<int> cu_fourth_cpu_w_offset_o;
    sc_signal<int> cu_fifth_cpu_w_offset_o;

    sc_signal<int> cu_first_cpu_a_offset_o;
    sc_signal<int> cu_second_cpu_a_offset_o;
    sc_signal<int> cu_third_cpu_a_offset_o;
    sc_signal<int> cu_fourth_cpu_a_offset_o;
    sc_signal<int> cu_fifth_cpu_a_offset_o;

    sc_signal<int> cu_first_cpu_n_offset_o;
    sc_signal<int> cu_second_cpu_n_offset_o;
    sc_signal<int> cu_third_cpu_n_offset_o;
    sc_signal<int> cu_fourth_cpu_n_offset_o;
    sc_signal<int> cu_fifth_cpu_n_offset_o;

    sc_signal<int> cu_addr_bo;
    sc_signal<bool> cu_wr_bo;
    sc_signal<bool> cu_rd_bo;

    sc_signal<float> bus_first_cpu_data_o;
    sc_signal<float> bus_second_cpu_data_o;
    sc_signal<float> bus_third_cpu_data_o;
    sc_signal<float> bus_fourth_cpu_data_o;
    sc_signal<float> bus_fifth_cpu_data_o;
    sc_signal<float> bus_cu_data_o;
    sc_signal<bool> bus_busy_o;

    sc_signal<float> bus_ioc_data_o;
    sc_signal<bool> bus_first_cpu_busy_o;
    sc_signal<bool> bus_second_cpu_busy_o;
    sc_signal<bool> bus_third_cpu_busy_o;
    sc_signal<bool> bus_fourth_cpu_busy_o;
    sc_signal<bool> bus_fifth_cpu_busy_o;

    sc_signal<bool> bus_first_cpu_d_ready_o;
    sc_signal<bool> bus_second_cpu_d_ready_o;
    sc_signal<bool> bus_third_cpu_d_ready_o;
    sc_signal<bool> bus_fourth_cpu_d_ready_o;
    sc_signal<bool> bus_fifth_cpu_d_ready_o;

    sc_signal<int> ioc_addr_bo;
    sc_signal<float> ioc_data_bo;
    sc_signal<bool> cu_ioc_wr_o;
    sc_signal<bool> cu_ioc_rd_o;
    sc_signal<bool> ioc_wr_bo;
    sc_signal<bool> ioc_rd_bo;
    sc_signal <bool> ioc_busy_o;

    sc_signal<float> first_lmem_data_bo;
    sc_signal<int> bus_first_lmem_addr_o;
    sc_signal<float> bus_first_lmem_data_o;
    sc_signal<bool> bus_first_lmem_wr_o;
    sc_signal<bool> bus_first_lmem_rd_o;
    sc_signal<int> first_cpu_addr_lmem_o;
    sc_signal<int> second_cpu_addr_lmem_o;
    sc_signal<int> third_cpu_addr_lmem_o;
    sc_signal<int> fourth_cpu_addr_lmem_o;
    sc_signal<int> fifth_cpu_addr_lmem_o;
    sc_signal<float> first_lmem_data_o;
    sc_signal<float> second_lmem_data_o;
    sc_signal<float> third_lmem_data_o;
    sc_signal<float> fourth_lmem_data_o;
    sc_signal<float> fifth_lmem_data_o;
    sc_signal<bool> first_cpu_rd_lmem_o;
    sc_signal<bool> second_cpu_rd_lmem_o;
    sc_signal<bool> third_cpu_rd_lmem_o;
    sc_signal<bool> fourth_cpu_rd_lmem_o;
    sc_signal<bool> fifth_cpu_rd_lmem_o;

    sc_signal<int> second_lmem_data_bo;
    sc_signal<int> bus_second_lmem_addr_o;
    sc_signal<float> bus_second_lmem_data_o;
    sc_signal<bool> bus_second_lmem_wr_o;
    sc_signal<bool> bus_second_lmem_rd_o;

    sc_signal<int> third_lmem_data_bo;
    sc_signal<int> bus_third_lmem_addr_o;
    sc_signal<float> bus_third_lmem_data_o;
    sc_signal<bool> bus_third_lmem_wr_o;
    sc_signal<bool> bus_third_lmem_rd_o;

    sc_signal<int> fourth_lmem_data_bo;
    sc_signal<int> bus_fourth_lmem_addr_o;
    sc_signal<float> bus_fourth_lmem_data_o;
    sc_signal<bool> bus_fourth_lmem_wr_o;
    sc_signal<bool> bus_fourth_lmem_rd_o;
    sc_signal<int> fifth_lmem_data_bo;
    sc_signal<int> bus_fifth_lmem_addr_o;
    sc_signal<float> bus_fifth_lmem_data_o;
    sc_signal<bool> bus_fifth_lmem_wr_o;
    sc_signal<bool> bus_fifth_lmem_rd_o;

    first_cpu_core.clk_i(clk);
    first_cpu_core.addr_bo(first_cpu_addr_bo);
    first_cpu_core.data_bi(bus_first_cpu_data_o);
    first_cpu_core.start_i(cu_first_cpu_start_o);
    first_cpu_core.a_size_i(cu_first_cpu_a_size_o);
    first_cpu_core.curr_neuron_i(cu_first_cpu_curr_neuron_o);
    first_cpu_core.w_offset_i(cu_first_cpu_w_offset_o);
    first_cpu_core.a_offset_i(cu_first_cpu_a_offset_o);
    first_cpu_core.n_offset_i(cu_first_cpu_n_offset_o);
    first_cpu_core.data_lmi(first_lmem_data_o);
    first_cpu_core.busy_bi(bus_first_cpu_busy_o);
    first_cpu_core.d_ready_i(bus_first_cpu_d_ready_o);
    first_cpu_core.data_bo(first_cpu_data_bo);
    first_cpu_core.addr_lmo(first_cpu_addr_lmem_o);
    first_cpu_core.rd_lmo(first_cpu_rd_lmem_o);
    first_cpu_core.wr_o(first_cpu_wr_bo);
    first_cpu_core.rd_o(first_cpu_rd_bo);
    first_cpu_core.busy_o(first_cpu_busy_o);

    second_cpu_core.clk_i(clk);
    second_cpu_core.addr_bo(second_cpu_addr_bo);
    second_cpu_core.data_bi(bus_second_cpu_data_o);
    second_cpu_core.start_i(cu_second_cpu_start_o);
    second_cpu_core.a_size_i(cu_second_cpu_a_size_o);
    second_cpu_core.curr_neuron_i(cu_second_cpu_curr_neuron_o);
    second_cpu_core.w_offset_i(cu_second_cpu_w_offset_o);
    second_cpu_core.a_offset_i(cu_second_cpu_a_offset_o);
    second_cpu_core.n_offset_i(cu_second_cpu_n_offset_o);
    second_cpu_core.data_lmi(second_lmem_data_o);
    second_cpu_core.busy_bi(bus_second_cpu_busy_o);
    second_cpu_core.d_ready_i(bus_second_cpu_d_ready_o);
    second_cpu_core.data_bo(second_cpu_data_bo);
    second_cpu_core.addr_lmo(second_cpu_addr_lmem_o);
    second_cpu_core.rd_lmo(second_cpu_rd_lmem_o);
    second_cpu_core.wr_o(second_cpu_wr_bo);
    second_cpu_core.rd_o(second_cpu_rd_bo);
    second_cpu_core.busy_o(second_cpu_busy_o);

    third_cpu_core.clk_i(clk);
    third_cpu_core.addr_bo(third_cpu_addr_bo);
    third_cpu_core.data_bi(bus_third_cpu_data_o);
    third_cpu_core.start_i(cu_third_cpu_start_o);
    third_cpu_core.a_size_i(cu_third_cpu_a_size_o);
    third_cpu_core.curr_neuron_i(cu_third_cpu_curr_neuron_o);
    third_cpu_core.w_offset_i(cu_third_cpu_w_offset_o);
    third_cpu_core.a_offset_i(cu_third_cpu_a_offset_o);
    third_cpu_core.n_offset_i(cu_third_cpu_n_offset_o);
    third_cpu_core.data_lmi(third_lmem_data_o);
    third_cpu_core.busy_bi(bus_third_cpu_busy_o);
    third_cpu_core.data_bo(third_cpu_data_bo);
    third_cpu_core.d_ready_i(bus_third_cpu_d_ready_o);
    third_cpu_core.addr_lmo(third_cpu_addr_lmem_o);
    third_cpu_core.rd_lmo(third_cpu_rd_lmem_o);
    third_cpu_core.wr_o(third_cpu_wr_bo);
    third_cpu_core.rd_o(third_cpu_rd_bo);
    third_cpu_core.busy_o(third_cpu_busy_o);

    fourth_cpu_core.clk_i(clk);
    fourth_cpu_core.addr_bo(fourth_cpu_addr_bo);
    fourth_cpu_core.data_bi(bus_fourth_cpu_data_o);
    fourth_cpu_core.start_i(cu_fourth_cpu_start_o);
    fourth_cpu_core.a_size_i(cu_fourth_cpu_a_size_o);
    fourth_cpu_core.curr_neuron_i(cu_fourth_cpu_curr_neuron_o);
    fourth_cpu_core.w_offset_i(cu_fourth_cpu_w_offset_o);
    fourth_cpu_core.a_offset_i(cu_fourth_cpu_a_offset_o);
    fourth_cpu_core.n_offset_i(cu_fourth_cpu_n_offset_o);
    fourth_cpu_core.data_lmi(fourth_lmem_data_o);
    fourth_cpu_core.busy_bi(bus_fourth_cpu_busy_o);
    fourth_cpu_core.d_ready_i(bus_fourth_cpu_d_ready_o);
    fourth_cpu_core.data_bo(fourth_cpu_data_bo);
    fourth_cpu_core.addr_lmo(fourth_cpu_addr_lmem_o);
    fourth_cpu_core.rd_lmo(fourth_cpu_rd_lmem_o);
    fourth_cpu_core.wr_o(fourth_cpu_wr_bo);
    fourth_cpu_core.rd_o(fourth_cpu_rd_bo);
    fourth_cpu_core.busy_o(fourth_cpu_busy_o);

    fifth_cpu_core.clk_i(clk);
    fifth_cpu_core.addr_bo(fifth_cpu_addr_bo);
    fifth_cpu_core.data_bi(bus_fifth_cpu_data_o);
    fifth_cpu_core.start_i(cu_fifth_cpu_start_o);
    fifth_cpu_core.a_size_i(cu_fifth_cpu_a_size_o);
    fifth_cpu_core.curr_neuron_i(cu_fifth_cpu_curr_neuron_o);
    fifth_cpu_core.w_offset_i(cu_fifth_cpu_w_offset_o);
    fifth_cpu_core.a_offset_i(cu_fifth_cpu_a_offset_o);
    fifth_cpu_core.n_offset_i(cu_fifth_cpu_n_offset_o);
    fifth_cpu_core.data_lmi(fifth_lmem_data_o);
    fifth_cpu_core.busy_bi(bus_fifth_cpu_busy_o);
    fifth_cpu_core.d_ready_i(bus_fifth_cpu_d_ready_o);
    fifth_cpu_core.data_bo(fifth_cpu_data_bo);
    fifth_cpu_core.addr_lmo(fifth_cpu_addr_lmem_o);
    fifth_cpu_core.rd_lmo(fifth_cpu_rd_lmem_o);
    fifth_cpu_core.wr_o(fifth_cpu_wr_bo);
    fifth_cpu_core.rd_o(fifth_cpu_rd_bo);
    fifth_cpu_core.busy_o(fifth_cpu_busy_o);

    first_lmem.clk_i(clk);
    first_lmem.addr_bi(bus_first_lmem_addr_o);
    first_lmem.data_bi(bus_first_lmem_data_o);
    first_lmem.data_o(first_lmem_data_o);
    first_lmem.wr_i(bus_first_lmem_wr_o);
    first_lmem.rd_i(first_cpu_rd_lmem_o);
    first_lmem.addr_i(first_cpu_addr_lmem_o);

    second_lmem.clk_i(clk);
    second_lmem.addr_bi(bus_second_lmem_addr_o);
    second_lmem.data_bi(bus_second_lmem_data_o);
    second_lmem.data_o(second_lmem_data_o);
    second_lmem.wr_i(bus_second_lmem_wr_o);
    second_lmem.rd_i(second_cpu_rd_lmem_o);
    second_lmem.addr_i(second_cpu_addr_lmem_o);

    third_lmem.clk_i(clk);
    third_lmem.addr_bi(bus_third_lmem_addr_o);
    third_lmem.data_bi(bus_third_lmem_data_o);
    third_lmem.data_o(third_lmem_data_o);
    third_lmem.wr_i(bus_third_lmem_wr_o);
    third_lmem.rd_i(third_cpu_rd_lmem_o);
    third_lmem.addr_i(third_cpu_addr_lmem_o);

    fourth_lmem.clk_i(clk);
    fourth_lmem.addr_bi(bus_fourth_lmem_addr_o);
    fourth_lmem.data_bi(bus_fourth_lmem_data_o);
    fourth_lmem.data_o(fourth_lmem_data_o);
    fourth_lmem.wr_i(bus_fourth_lmem_wr_o);
    fourth_lmem.rd_i(fourth_cpu_rd_lmem_o);
    fourth_lmem.addr_i(fourth_cpu_addr_lmem_o);

    fifth_lmem.clk_i(clk);
    fifth_lmem.addr_bi(bus_fifth_lmem_addr_o);
    fifth_lmem.data_bi(bus_fifth_lmem_data_o);
    fifth_lmem.data_o(fifth_lmem_data_o);
    fifth_lmem.wr_i(bus_fifth_lmem_wr_o);
    fifth_lmem.rd_i(fifth_cpu_rd_lmem_o);
    fifth_lmem.addr_i(fifth_cpu_addr_lmem_o);

    ioc.clk_i(clk);
    ioc.addr_bo(ioc_addr_bo);
    ioc.data_bi(bus_ioc_data_o);
    ioc.data_bo(ioc_data_bo);
    ioc.cu_wr_i(cu_ioc_wr_o);
    ioc.cu_rd_i(cu_ioc_rd_o);
    ioc.wr_bo(ioc_wr_bo);
    ioc.rd_bo(ioc_rd_bo);
    ioc.busy_o(ioc_busy_o);

    cu.clk_i(clk);
    cu.ioc_wr_o(cu_ioc_wr_o);
    cu.ioc_rd_o(cu_ioc_rd_o);
    cu.ioc_busy_i(ioc_busy_o);
    cu.data_bi(bus_cu_data_o);
    cu.addr_bo(cu_addr_bo);
    cu.rd_bo(cu_rd_bo);
    cu.wr_bo(cu_wr_bo);
    cu.first_cpu_busy_i(first_cpu_busy_o);
    cu.first_cpu_start_o(cu_first_cpu_start_o);
    cu.second_cpu_busy_i(second_cpu_busy_o);
    cu.second_cpu_start_o(cu_second_cpu_start_o);
    cu.third_cpu_busy_i(third_cpu_busy_o);
    cu.third_cpu_start_o(cu_third_cpu_start_o);
    cu.fourth_cpu_busy_i(fourth_cpu_busy_o);
    cu.fourth_cpu_start_o(cu_fourth_cpu_start_o);
    cu.fifth_cpu_busy_i(fifth_cpu_busy_o);
    cu.fifth_cpu_start_o(cu_fifth_cpu_start_o);
    cu.a_size_first_cpu_o(cu_first_cpu_a_size_o);
    cu.a_size_second_cpu_o(cu_second_cpu_a_size_o);
    cu.a_size_third_cpu_o(cu_third_cpu_a_size_o);
    cu.a_size_fourth_cpu_o(cu_fourth_cpu_a_size_o);
    cu.a_size_fifth_cpu_o(cu_fifth_cpu_a_size_o);
    cu.curr_neuron_first_cpu_o(cu_first_cpu_curr_neuron_o);
    cu.curr_neuron_second_cpu_o(cu_second_cpu_curr_neuron_o);
    cu.curr_neuron_third_cpu_o(cu_third_cpu_curr_neuron_o);
    cu.curr_neuron_fourth_cpu_o(cu_fourth_cpu_curr_neuron_o);
    cu.curr_neuron_fifth_cpu_o(cu_fifth_cpu_curr_neuron_o);
    cu.w_offset_first_cpu_o(cu_first_cpu_w_offset_o);
    cu.w_offset_second_cpu_o(cu_second_cpu_w_offset_o);
    cu.w_offset_third_cpu_o(cu_third_cpu_w_offset_o);
    cu.w_offset_fourth_cpu_o(cu_fourth_cpu_w_offset_o);
    cu.w_offset_fifth_cpu_o(cu_fifth_cpu_w_offset_o);
    cu.a_offset_first_cpu_o(cu_first_cpu_a_offset_o);
    cu.a_offset_second_cpu_o(cu_second_cpu_a_offset_o);
    cu.a_offset_third_cpu_o(cu_third_cpu_a_offset_o);
    cu.a_offset_fourth_cpu_o(cu_fourth_cpu_a_offset_o);
    cu.a_offset_fifth_cpu_o(cu_fifth_cpu_a_offset_o);
    cu.n_offset_first_cpu_o(cu_first_cpu_n_offset_o);
    cu.n_offset_second_cpu_o(cu_second_cpu_n_offset_o);
    cu.n_offset_third_cpu_o(cu_third_cpu_n_offset_o);
    cu.n_offset_fourth_cpu_o(cu_fourth_cpu_n_offset_o);
    cu.n_offset_fifth_cpu_o(cu_fifth_cpu_n_offset_o);

    bus.clk_i(clk);

    bus.first_cpu_addr_i(first_cpu_addr_bo);
    bus.second_cpu_addr_i(second_cpu_addr_bo);
    bus.third_cpu_addr_i(third_cpu_addr_bo);
    bus.fourth_cpu_addr_i(fourth_cpu_addr_bo);
    bus.fifth_cpu_addr_i(fifth_cpu_addr_bo);
    bus.ioc_addr_i(ioc_addr_bo);
    bus.first_cpu_data_i(first_cpu_data_bo);
    bus.second_cpu_data_i(second_cpu_data_bo);
    bus.third_cpu_data_i(third_cpu_data_bo);
    bus.fourth_cpu_data_i(fourth_cpu_data_bo);
    bus.fifth_cpu_data_i(fifth_cpu_data_bo);
    bus.first_lmem_addr_o(bus_first_lmem_addr_o);
    bus.first_lmem_data_o(bus_first_lmem_data_o);
    bus.second_lmem_addr_o(bus_second_lmem_addr_o);
    bus.second_lmem_data_o(bus_second_lmem_data_o);
    bus.third_lmem_addr_o(bus_third_lmem_addr_o);
    bus.third_lmem_data_o(bus_third_lmem_data_o);
    bus.fourth_lmem_addr_o(bus_fourth_lmem_addr_o);
    bus.fourth_lmem_data_o(bus_fourth_lmem_data_o);
    bus.fifth_lmem_addr_o(bus_fifth_lmem_addr_o);
    bus.fifth_lmem_data_o(bus_fifth_lmem_data_o);
    bus.ioc_data_i(ioc_data_bo);
    bus.cu_addr_i(cu_addr_bo);
    bus.first_cpu_wr_i(first_cpu_wr_bo);
    bus.second_cpu_wr_i(second_cpu_wr_bo);
    bus.third_cpu_wr_i(third_cpu_wr_bo);
    bus.fourth_cpu_wr_i(fourth_cpu_wr_bo);
    bus.fifth_cpu_wr_i(fifth_cpu_wr_bo);
    bus.ioc_wr_i(ioc_wr_bo);
    bus.first_cpu_rd_i(first_cpu_rd_bo);
    bus.second_cpu_rd_i(second_cpu_rd_bo);
    bus.third_cpu_rd_i(third_cpu_rd_bo);
    bus.fourth_cpu_rd_i(fourth_cpu_rd_bo);
    bus.fifth_cpu_rd_i(fifth_cpu_rd_bo);
    bus.ioc_rd_i(ioc_rd_bo);
    bus.cu_rd_i(cu_rd_bo);
    bus.cu_wr_i(cu_wr_bo);
    bus.first_cpu_data_o(bus_first_cpu_data_o);
    bus.second_cpu_data_o(bus_second_cpu_data_o);
    bus.third_cpu_data_o(bus_third_cpu_data_o);
    bus.fourth_cpu_data_o(bus_fourth_cpu_data_o);
    bus.fifth_cpu_data_o(bus_fifth_cpu_data_o);
    bus.ioc_data_o(bus_ioc_data_o);
    bus.cu_data_o(bus_cu_data_o);
    bus.busy_o(bus_busy_o);
    bus.first_cpu_busy_o(bus_first_cpu_busy_o);
    bus.second_cpu_busy_o(bus_second_cpu_busy_o);
    bus.third_cpu_busy_o(bus_third_cpu_busy_o);
    bus.fourth_cpu_busy_o(bus_fourth_cpu_busy_o);
    bus.fifth_cpu_busy_o(bus_fifth_cpu_busy_o);
    bus.first_cpu_d_ready_o(bus_first_cpu_d_ready_o);
    bus.second_cpu_d_ready_o(bus_second_cpu_d_ready_o);
    bus.third_cpu_d_ready_o(bus_third_cpu_d_ready_o);
    bus.fourth_cpu_d_ready_o(bus_fourth_cpu_d_ready_o);
    bus.fifth_cpu_d_ready_o(bus_fifth_cpu_d_ready_o);
    bus.first_lmem_wr_o(bus_first_lmem_wr_o);
    bus.first_lmem_rd_o(bus_first_lmem_rd_o);
    bus.second_lmem_wr_o(bus_second_lmem_wr_o);
    bus.second_lmem_rd_o(bus_second_lmem_rd_o);
    bus.third_lmem_wr_o(bus_third_lmem_wr_o);
    bus.third_lmem_rd_o(bus_third_lmem_rd_o);
    bus.fourth_lmem_wr_o(bus_fourth_lmem_wr_o);
    bus.fourth_lmem_rd_o(bus_fourth_lmem_rd_o);
    bus.fifth_lmem_wr_o(bus_fifth_lmem_wr_o);
    bus.fifth_lmem_rd_o(bus_fifth_lmem_rd_o);

    sc_trace_file* wf = sc_create_vcd_trace_file("wave");

    sc_trace(wf, clk, "clk");
    sc_trace(wf, first_cpu_addr_bo, "cpu_addr_bo");
    sc_trace(wf, mem_data_i, "mem_data_i");
    sc_trace(wf, first_cpu_data_bo, "first_cpu_data_bo");
    sc_trace(wf, first_cpu_wr_bo, "first_cpu_wr_bo");
    sc_trace(wf, first_cpu_rd_bo, "first_cpu_rd_bo");
    sc_trace(wf, bus_first_lmem_addr_o, "bus_mem_addr_o");
    sc_trace(wf, bus_first_cpu_data_o, "bus_first_cpu_data_o");
    sc_trace(wf, bus_first_lmem_data_o, "bus_mem_data_o");
    sc_trace(wf, bus_first_cpu_busy_o, "bus_first_cpu_busy_o");
    sc_trace(wf, bus_second_cpu_busy_o, "bus_second_cpu_busy_o");
    sc_trace(wf, bus_first_lmem_wr_o, "bus_mem_wr_o");
    sc_trace(wf, bus_first_lmem_rd_o, "bus_mem_rd_o");
    sc_trace(wf, cu_ioc_wr_o, "cu_ioc_wr_o");
    sc_trace(wf, cu_ioc_rd_o, "cu_ioc_rd_o");
    sc_trace(wf, ioc_addr_bo, "ioc_addr_bo");
    sc_trace(wf, bus_ioc_data_o, "bus_ioc_data_o");
    sc_trace(wf, ioc_data_bo, "ioc_data_bo");
    sc_trace(wf, ioc_wr_bo, "ioc_wr_bo");
    sc_trace(wf, ioc_rd_bo, "ioc_rd_bo");
    sc_trace(wf, first_cpu_busy_o, "first_cpu_busy_o");
    sc_trace(wf, second_cpu_busy_o, "second_cpu_busy_o");
    sc_trace(wf, third_cpu_busy_o, "third_cpu_busy_o");
    sc_trace(wf, fourth_cpu_busy_o, "fourth_cpu_busy_o");
    sc_trace(wf, fifth_cpu_busy_o, "fifth_cpu_busy_o");
    sc_trace(wf, cu_first_cpu_start_o, "cu_first_cpu_start_o");
    sc_trace(wf, cu_second_cpu_start_o, "cu_second_cpu_start_o");
    sc_trace(wf, cu_third_cpu_start_o, "cu_third_cpu_start_o");
    sc_trace(wf, cu_fourth_cpu_start_o, "cu_fourth_cpu_start_o");
    sc_trace(wf, cu_fifth_cpu_start_o, "cu_fifth_cpu_start_o");
    sc_trace(wf, first_cpu_addr_bo, "first_cpu_addr_bo");
    sc_trace(wf, second_cpu_addr_bo, "second_cpu_addr_bo");
    sc_trace(wf, third_cpu_addr_bo, "third_cpu_addr_bo");
    sc_trace(wf, fourth_cpu_addr_bo, "fourth_cpu_addr_bo");
    sc_trace(wf, fifth_cpu_addr_bo, "fifth_cpu_addr_bo");
    sc_trace(wf, first_cpu_rd_bo, "first_cpu_rd_bo");
    sc_trace(wf, second_cpu_rd_bo, "second_cpu_rd_bo");
    sc_trace(wf, third_cpu_rd_bo, "third_cpu_rd_bo");
    sc_trace(wf, fourth_cpu_rd_bo, "fourth_cpu_rd_bo");
    sc_trace(wf, fifth_cpu_rd_bo, "fifth_cpu_rd_bo");
    sc_trace(wf, bus_first_cpu_d_ready_o, "bus_first_cpu_d_ready_o");
    sc_trace(wf, bus_second_cpu_d_ready_o, "bus_second_cpu_d_ready_o");
    sc_trace(wf, bus_third_cpu_d_ready_o, "bus_third_cpu_d_ready_o");
    sc_trace(wf, bus_fourth_cpu_d_ready_o, "bus_fourth_cpu_d_ready_o");
    sc_trace(wf, bus_fifth_cpu_d_ready_o, "bus_fifth_cpu_d_ready_o");

    sc_start();

    sc_close_vcd_trace_file(wf);

    return(0);
}
